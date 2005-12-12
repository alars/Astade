#include <cstdlib>
#include <iostream>
#include <map>
#include <wx/app.h>
#include <wx/dir.h>
#include <wx/filename.h>
#include <wx/string.h>
#include <wx/textfile.h>
#include <wx/utils.h>
#include <wx/cmdline.h>
#include "../include/AdeDefines.h"
#include <list>

#ifdef __WXGTK__
WXDLLEXPORT bool wxGetResource(const wxString& section, const wxString& entry, wxChar **value, const wxString& file = wxEmptyString);
WXDLLEXPORT bool wxGetResource(const wxString& section, const wxString& entry, float *value, const wxString& file = wxEmptyString);
WXDLLEXPORT bool wxGetResource(const wxString& section, const wxString& entry, long *value, const wxString& file = wxEmptyString);
WXDLLEXPORT bool wxGetResource(const wxString& section, const wxString& entry, int *value, const wxString& file = wxEmptyString);
#endif

std::list<wxString> AttributeList;
wxString theClassname;
wxString theAdditionalClasses;
wxFileName dirname;
std::map<wxString,wxString> memberDefaults;
std::map<wxString,wxString> RelationTypes;
wxFileName theFileName;

wxString Decode(wxString input)
{
    input.Replace("\\n","\n");
    input.Replace("\\r","\r");
    input.Replace("\\\"","\"");
    input.Replace("\\\'","\'");
    return input;
}    

void staticAttribute(FILE* f, bool spec, int visibility)
{
    std::map<wxString,wxString> attributenames;
    std::map<wxString,wxString> attributedefaults;

    wxFileName attributes(dirname);
    attributes.AppendDir("attributes");
     
    if (wxDir::Exists(attributes.GetPath()))
    {
        wxDir dir(attributes.GetPath());
        wxString filename;
        
        bool cont = dir.GetFirst(&filename, "*.ini");
        while ( cont )
        {
            wxFileName FullName = attributes;
            FullName.SetFullName(filename);
            wxChar* name = NULL;
            int type = 0;
            
            wxGetResource("Astade","Type",&type,FullName.GetFullPath());
            if (((0xFF00000 & type) == ITEM_IS_ATTRIBUTE) &&
                ((type & visibility) == visibility))
            {
                wxGetResource("Astade","Name",&name,FullName.GetFullPath());
                wxString theName(name);
                delete [] name;
                name = NULL;
                wxGetResource("Astade","CodingType",&name,FullName.GetFullPath());
                wxString CodingType(name);
                delete [] name;
                name = NULL;
                wxGetResource("Astade","Static",&name,FullName.GetFullPath());
                wxString Static(name);
                delete [] name;
                name = NULL;
                wxGetResource("Astade","Default",&name,FullName.GetFullPath());
                wxString Default(name);
                delete [] name;
                name = NULL;
                
                if (Static == "yes")
                {
                    attributenames[theName] = CodingType;
                    if (Default.size()>0)
                        attributedefaults[theName] = Decode(Default);
                }    
            }    
            cont = dir.GetNext(&filename);
        }    
    }
    
    std::map<wxString,wxString>::iterator it;
    
    for (it = attributenames.begin(); it != attributenames.end(); ++it)
    {
        if (!spec)
            fprintf(f,"\tstatic %s\t%s;\n",(*it).second.c_str(),(*it).first.c_str());
        else
        {
            if (attributedefaults.find((*it).first)!=attributedefaults.end())
                fprintf(f,"%s %s::%s = %s;\n",(*it).second.c_str(),theClassname.c_str(),(*it).first.c_str(),attributedefaults[(*it).first].c_str());
            else
                fprintf(f,"%s %s::%s;\n",(*it).second.c_str(),theClassname.c_str(),(*it).first.c_str());
        }    
    }   
}

void memberAttribute(FILE* f, bool spec, int visibility)
{
    std::map<wxString,wxString> attributenames;
    std::map<wxString,wxString> attributedefaults;

    wxFileName attributes(dirname);
    attributes.AppendDir("attributes");
     
    if (wxDir::Exists(attributes.GetPath()))
    {
        wxDir dir(attributes.GetPath());
        wxString filename;
        
        bool cont = dir.GetFirst(&filename, "*.ini");
        while ( cont )
        {
            wxFileName FullName = attributes;
            FullName.SetFullName(filename);
            wxChar* name = NULL;
            int type = 0;
            
            wxGetResource("Astade","Type",&type,FullName.GetFullPath());
            if (((0xFF00000 & type) == ITEM_IS_ATTRIBUTE) &&
                ((type & visibility) == visibility))
            {
                wxGetResource("Astade","Name",&name,FullName.GetFullPath());
                wxString theName(name);
                delete [] name;
                name = NULL;
                wxGetResource("Astade","CodingType",&name,FullName.GetFullPath());
                wxString CodingType(name);
                delete [] name;
                name = NULL;
                wxGetResource("Astade","Static",&name,FullName.GetFullPath());
                wxString Static(name);
                delete [] name;
                name = NULL;
                wxGetResource("Astade","Default",&name,FullName.GetFullPath());
                wxString Default(name);
                delete [] name;
                name = NULL;
                
                if (Static!="yes")
                {
                    attributenames[theName] = CodingType;
                    if (Default.size()>0)
                        memberDefaults[theName] = Decode(Default);
                }    
            }    
            cont = dir.GetNext(&filename);
        }    
    }
    
    std::map<wxString,wxString>::iterator it;
    
    for (it = attributenames.begin(); it != attributenames.end(); ++it)
    {
        if (!spec)
        {
            fprintf(f,"\t%s\t%s;\n",(*it).second.c_str(),(*it).first.c_str());
            AttributeList.push_back((*it).first);
        }    
    }   
}

void memberType(FILE* f)
{
    wxFileName attributes(dirname);
    attributes.AppendDir("types");
     
    if (wxDir::Exists(attributes.GetPath()))
    {
        wxDir dir(attributes.GetPath());
        wxString filename;
        
        bool cont = dir.GetFirst(&filename, "*.ini");
        while ( cont )
        {
            wxFileName FullName = attributes;
            FullName.SetFullName(filename);
            wxChar* name = NULL;
            int type = 0;
            
            wxGetResource("Astade","Type",&type,FullName.GetFullPath());
            if (((0xFF00000 & type) == ITEM_IS_TYPE))
            {
                wxGetResource("Astade","Declaration",&name,FullName.GetFullPath());
                wxString theName(Decode(name));
                delete [] name;
                name = NULL;
            
                fprintf(f,"\t%s\n",theName.c_str());
            }    
            cont = dir.GetNext(&filename);
        }    
    }
}

wxString Paramlist(wxString Operationpath)
{
    wxFileName parameterPath = Operationpath;
    parameterPath.AppendDir("parameters");
    wxString paramlist;
                
    if (wxDir::Exists(parameterPath.GetPath()))
    {
        wxDir dir(parameterPath.GetPath());
        wxString filename;
                
        bool cont = dir.GetFirst(&filename,"*.ini");
                
        wxString params[256];
        wxString types[256];
                
        while ( cont )
        {
            wxFileName newPath(parameterPath);
            newPath.SetFullName(filename);
                    
            int type;
            wxGetResource("Astade","Type", &type, newPath.GetFullPath());
                    
            if ((type & ITEM_IS_PARAMETER) == ITEM_IS_PARAMETER)
            {
                int number = type & 0xff;
    
                wxChar* name = NULL;
                wxGetResource("Astade","Name", &name, newPath.GetFullPath());
                params[number] = name;
                delete [] name;
                name = NULL;
                wxGetResource("Astade","CodingType", &name, newPath.GetFullPath());
                types[number] = Decode(name);
                delete [] name;
                name = NULL;
            }
    
            cont = dir.GetNext(&filename);
         }
    
         for (int i=0;i<256;++i)
         {
             if (params[i].length()!=0)
             {
                 if (paramlist.length()!=0)
                     paramlist = paramlist + ",";
                 paramlist = paramlist + types[i] + " " + params[i];
             }    
         }  
    }           
    return paramlist;
}    

wxString InitializerList(wxString Operationpath)
{
    wxFileName parameterPath = Operationpath;
    wxChar* name = NULL;
    wxGetResource("Astade","Initializer", &name, Operationpath);
    wxString paramlist(Decode(name));
    if (!paramlist.empty())
       paramlist = ":\n\t" + paramlist; 
    delete name;
    
    while (!AttributeList.empty())
    {
        if (!memberDefaults[AttributeList.front()].empty())
        {
            if (paramlist.empty())
                paramlist = ":\n\t" + AttributeList.front() + "(" + memberDefaults[AttributeList.front()] + ")";
            else
                paramlist = paramlist + ",\n\t" + AttributeList.front() + "(" + memberDefaults[AttributeList.front()] + ")";
        }    
        AttributeList.pop_front();
    }    
    return paramlist;
}    

void operations(FILE* f, bool spec, int visibility)
{
    std::map<wxString,wxString> operationnames;
    std::map<wxString,wxString> operationtypes;
    std::map<wxString,bool> operationvirtual;
    std::map<wxString,bool> operationabstract;
    std::map<wxString,bool> operationconst;
    std::map<wxString,bool> operationstatic;
    std::map<wxString,wxTextFile*> code;

    wxFileName operation(dirname);
    operation.AppendDir("operations");
     
    if (wxDir::Exists(operation.GetPath()))
    {
        wxDir dir(operation.GetPath());
        wxString filename;
        
        bool cont = dir.GetFirst(&filename,wxEmptyString,wxDIR_DIRS);
        while ( cont )
        {
            wxFileName FullName = operation;
            FullName.AppendDir(filename);
            
            FullName.SetFullName("ModelNode.ini");
            wxChar* name = NULL;
            int type = 0;
            
            wxGetResource("Astade","Type",&type,FullName.GetFullPath());
            if (((0xFF00000 & type) == ITEM_IS_OPERATION) &&
                ((type & visibility) == visibility))
            {
                wxGetResource("Astade","Name",&name,FullName.GetFullPath());
                wxString theName(name);
                delete [] name;
                name = NULL;
                wxGetResource("Astade","CodingType",&name,FullName.GetFullPath());
                wxString CodingType(name);
                delete [] name;
                name = NULL;
                wxGetResource("Astade","Static",&name,FullName.GetFullPath());
                wxString Static(name);
                delete [] name;
                name = NULL;
                wxGetResource("Astade","Const",&name,FullName.GetFullPath());
                wxString Const(name);
                delete [] name;
                name = NULL;
                wxGetResource("Astade","Virtual",&name,FullName.GetFullPath());
                wxString Virtual(name);
                delete [] name;
                name = NULL;
                wxGetResource("Astade","Abstract",&name,FullName.GetFullPath());
                wxString Abstract(name);
                delete [] name;
                name = NULL;
                
                operationnames[FullName.GetFullPath()] = theName;
                
                if ((type&ITEM_IS_DEST)==ITEM_IS_DEST)
                    operationnames[FullName.GetFullPath()] = "~" + theClassname;
                else
                if ((type&ITEM_IS_NORMALOP)!=ITEM_IS_NORMALOP)
                    operationnames[FullName.GetFullPath()] = theClassname;
                
                if (Virtual=="yes")
                {
                    operationvirtual[FullName.GetFullPath()] = true;
                    if (!spec)
                        CodingType = "virtual " + CodingType;
                }    
                if (Abstract=="yes")
                    operationabstract[FullName.GetFullPath()] = true;
                if (Static=="yes")
                    operationstatic[FullName.GetFullPath()] = true;
                if (Const=="yes")
                    operationconst[FullName.GetFullPath()] = true;
                
                operationtypes[FullName.GetFullPath()] = CodingType;
                wxFileName CodeName = FullName;
                CodeName.SetFullName("code.cpp");
                code[FullName.GetFullPath()] = new wxTextFile(CodeName.GetFullPath());
                if (code[FullName.GetFullPath()]->Exists())
                    code[FullName.GetFullPath()]->Open(CodeName.GetFullPath());

            }    
            cont = dir.GetNext(&filename);
        }    
    }
    
    std::map<wxString,wxString>::iterator it;
    
    for (it = operationnames.begin(); it != operationnames.end(); ++it)
    {
        if (spec)
        {
            fprintf(f,"\n");
            
            if (theClassname==(*it).second)
            {
                if (operationtypes[(*it).first].empty())
                    fprintf(f,"%s::%s(%s)%s\n{\n", theClassname.c_str(), (*it).second.c_str(), Paramlist((*it).first).c_str(), InitializerList((*it).first).c_str());
                else    
                    fprintf(f,"%s %s::%s(%s)%s\n{\n", operationtypes[(*it).first].c_str(), theClassname.c_str(), (*it).second.c_str(), Paramlist((*it).first).c_str(), InitializerList((*it).first).c_str());
            }
            else
            {        
                wxString Const;
                if (operationconst.find((*it).first) != operationconst.end())
                    Const = " const";
                if (operationtypes[(*it).first].empty())
                    fprintf(f,"%s::%s(%s)%s\n{\n", theClassname.c_str(), (*it).second.c_str(), Paramlist((*it).first).c_str(), Const.c_str());
                else    
                    fprintf(f,"%s %s::%s(%s)%s\n{\n", operationtypes[(*it).first].c_str(), theClassname.c_str(), (*it).second.c_str(), Paramlist((*it).first).c_str(), Const.c_str());
            }
            
            if ((code[(*it).first]->IsOpened()) && (code[(*it).first]->GetLineCount()>=1) )
            {
                wxString str;
                for ( str = code[(*it).first]->GetFirstLine(); !code[(*it).first]->Eof(); str = code[(*it).first]->GetNextLine() )
                {
                    fprintf(f,"\t%s\n",str.c_str());
                }
                if (str.size())
                    fprintf(f,"\t%s\n",str.c_str());
            }    
            delete code[(*it).first];
            fprintf(f,"};\n");
        }
        else    
        {
            wxString Static;
            if (operationstatic.find((*it).first) != operationstatic.end())
                Static = "static ";
            wxString Const;
            if (operationconst.find((*it).first) != operationconst.end())
                Const = " const";
            wxString Abstract;
            if (operationabstract.find((*it).first) != operationabstract.end())
                Abstract = " = 0";
                
            if (operationtypes[(*it).first].empty())
                fprintf(f,"\t%s%s(%s)%s%s;\n", Static.c_str(), (*it).second.c_str(), Paramlist((*it).first).c_str(), Const.c_str(), Abstract.c_str());
            else
                fprintf(f,"\t%s%s %s(%s)%s%s;\n", Static.c_str(), operationtypes[(*it).first].c_str(), (*it).second.c_str(), Paramlist((*it).first).c_str(), Const.c_str(), Abstract.c_str());
        }    
    }   
}

void RelationIncludes(FILE* f, bool spec)
{
    std::map<wxString,bool> filenames;

    wxFileName relations(dirname);
    relations.AppendDir("relations");
     
    wxDir dir(relations.GetPath());
    wxString filename;
    
    bool cont = dir.GetFirst(&filename, "*.ini");
    while ( cont )
    {
        wxFileName FullName = relations;
        FullName.SetFullName(filename);
        wxChar* name = NULL;
        int type = 0;
        
        wxGetResource("Astade","Type",&type,FullName.GetFullPath());
        if ((0xFF00000 & type) == ITEM_IS_RELATION)
        {
            wxGetResource("Astade","PartnerPath",&name,FullName.GetFullPath());
            wxFileName PartnerDir(name);
            PartnerDir.MakeAbsolute();
            delete [] name;
            name = NULL;
            wxGetResource("Astade","RelationType",&name,FullName.GetFullPath());
            wxString RelationType(name);
            delete [] name;
            name = NULL;
            wxGetResource("Astade","Name",&name,FullName.GetFullPath());
            wxString RelationName(name);
            delete [] name;
            name = NULL;
            wxGetResource("Astade","Implementation",&name,FullName.GetFullPath());
            wxString RelationImplementation(name);
            delete [] name;
            name = NULL;
            
            if (RelationType=="Generalization")
            {
                wxFileName partnerName = PartnerDir;
                int i = partnerName.GetDirCount();
                partnerName.RemoveDir(i-1);
                partnerName.SetName("ModelNode"); 
                partnerName.SetExt("ini");
                wxGetResource("Astade","Name", &name, partnerName.GetFullPath());
                wxString PartnerClassname(name);
                delete [] name;
                name = NULL;

                if (theAdditionalClasses.size()>0)
                    theAdditionalClasses = theAdditionalClasses + ", ";
                theAdditionalClasses = theAdditionalClasses + "public " + PartnerClassname;
            }
                 
            if ((RelationType=="Aggregation") || 
                (RelationType=="Association") ||
                (RelationType=="Composition"))
            {
                RelationTypes[RelationName] = RelationImplementation;
            }    
                
            if (((!spec) && (RelationType!="ImplementationDependency")) || 
                (( spec) && (RelationType=="ImplementationDependency")))
            {
                wxFileName partnerName = PartnerDir;
                int i = partnerName.GetDirCount();
                partnerName.RemoveDir(i-1);
                partnerName.SetName("ModelNode"); 
                partnerName.SetExt("ini");
                wxGetResource("Astade","Name", &name, partnerName.GetFullPath());
                wxString PartnerClassname(name);
                delete [] name;
                name = NULL;
                wxString PartnerHeadername = PartnerClassname + ".h";
                
                if (PartnerClassname!=theClassname)
                    filenames[PartnerHeadername] = true;
            }    
        }    
        cont = dir.GetNext(&filename);
    }

    std::map<wxString,bool>::iterator it;
    
    if (!filenames.empty())
        fprintf(f,"// Relation includes:\n");
    
    for (it=filenames.begin();it!=filenames.end();++it)
    {
        fprintf(f,"#include \"%s\"\n",(*it).first.c_str());
    }   
    fprintf(f,"\n");
}

void doHpp()
{
    FILE* f;
    theFileName.SetExt("h");
    f = fopen(theFileName.GetFullPath().c_str(),"w");
    fprintf(f,"//******************************************************\n");
    fprintf(f,"//** Coding is done with Astade Quick and Dirty Coder **\n");
    fprintf(f,"//** Filename: %-39s**\n",theFileName.GetFullName().c_str());
    fprintf(f,"//******************************************************\n\n");
    
    wxString defname = theFileName.GetFullName();
    defname.MakeUpper();
    defname.Replace(".","_");

    fprintf(f,"#ifndef %s\n",defname.c_str());
    fprintf(f,"#define %s\n\n",defname.c_str());

    wxFileName PrefixName = dirname;
    PrefixName.SetFullName("prolog.h");
    wxTextFile prefixtext(PrefixName.GetFullPath());

    if (prefixtext.Exists())
        prefixtext.Open();

    if (prefixtext.IsOpened() )
    {
        fprintf(f,"//****** specification prolog ******\n");
        wxString str;
        for ( str = prefixtext.GetFirstLine(); !prefixtext.Eof(); str = prefixtext.GetNextLine() )
        {
            fprintf(f,"%s\n",str.c_str());
        }
        if (str.size())
            fprintf(f,"%s\n",str.c_str());
        fprintf(f,"//**********************************\n");
    }

    RelationIncludes(f,false);    
    
    fprintf(f,"class %s",theClassname.c_str());
    if (theAdditionalClasses.size()!=0)
        fprintf(f," : %s",theAdditionalClasses.c_str());
    fprintf(f,"\n{\n");
    
    fprintf(f,"\tpublic:\n",theClassname.c_str());
    staticAttribute(f,false,ITEM_IS_PUBLIC);
    memberType(f);
    memberAttribute(f,false,ITEM_IS_PUBLIC);
    operations(f,false,ITEM_IS_PUBLIC);

    fprintf(f,"\n\tprotected:\n",theClassname.c_str());
    staticAttribute(f,false,ITEM_IS_PROTECTED);
    memberAttribute(f,false,ITEM_IS_PROTECTED);

    std::map<wxString,wxString>::iterator it;

    for (it=RelationTypes.begin();it!=RelationTypes.end();++it)
    {
        fprintf(f,"\t%s\t%s;\n",(*it).second.c_str(),(*it).first.c_str());
    }
    operations(f,false,ITEM_IS_PROTECTED);

    fprintf(f,"\n\tprivate:\n",theClassname.c_str());
    staticAttribute(f,false,ITEM_IS_PRIVATE);
    memberAttribute(f,false,ITEM_IS_PRIVATE);
    operations(f,false,ITEM_IS_PRIVATE);

    fprintf(f,"};\n\n");

    wxFileName PostfixName = dirname;
    PostfixName.SetFullName("epilog.h");
    wxTextFile postfixtext(PostfixName.GetFullPath());

    if (postfixtext.Exists())
        postfixtext.Open();

    if (postfixtext.IsOpened())
    {
        fprintf(f,"//****** specification epilog ******\n");
        wxString str;
        for (str = postfixtext.GetFirstLine(); !postfixtext.Eof(); str = postfixtext.GetNextLine())
        {
            fprintf(f,"%s\n",str.c_str());
        }
        if (str.size())
            fprintf(f,"%s\n",str.c_str());
        fprintf(f,"//**********************************\n");
    }

    fprintf(f,"#endif\n");
    fclose(f);
}

void doCpp()
{
    FILE* f;
    theFileName.SetExt("cpp");
    f = fopen(theFileName.GetFullPath().c_str(),"w");
    fprintf(f,"//******************************************************\n");
    fprintf(f,"//** Coding is done with Astade Quick and Dirty Coder **\n");
    fprintf(f,"//** Filename: %-39s**\n",theFileName.GetFullName().c_str());
    fprintf(f,"//******************************************************\n\n");

    wxFileName PrefixName = dirname;
    PrefixName.SetFullName("prolog.cpp");
    wxTextFile prefixtext(PrefixName.GetFullPath());

    if (prefixtext.Exists())
        prefixtext.Open();

    if (prefixtext.IsOpened() )
    {
        wxString str;
        fprintf(f,"//****** implementation prolog ******\n");
        for ( str = prefixtext.GetFirstLine(); !prefixtext.Eof(); str = prefixtext.GetNextLine() )
        {
            fprintf(f,"%s\n",str.c_str());
        }
        if (str.size())
            fprintf(f,"%s\n",str.c_str());
        fprintf(f,"//***********************************\n");
    }

    theFileName.SetExt("h");
    fprintf(f,"#include \"%s\" // own header\n\n",theFileName.GetFullName().c_str());

    RelationIncludes(f,true);
    staticAttribute(f,true,ITEM_IS_PUBLIC);
    staticAttribute(f,true,ITEM_IS_PROTECTED);
    staticAttribute(f,true,ITEM_IS_PRIVATE);
    operations(f,true,ITEM_IS_PUBLIC);
    operations(f,true,ITEM_IS_PROTECTED);
    operations(f,true,ITEM_IS_PRIVATE);

    wxFileName PostfixName = dirname;
    PostfixName.SetFullName("epilog.cpp");
    wxTextFile postfixtext(PostfixName.GetFullPath());

    if (postfixtext.Exists())
        postfixtext.Open();

    if (postfixtext.IsOpened() )
    {
        wxString str;
        fprintf(f,"//****** implementation epilog ******\n");
        for (str = postfixtext.GetFirstLine(); !postfixtext.Eof(); str = postfixtext.GetNextLine())
        {
            fprintf(f,"%s\n",str.c_str());
        }
        if (str.size())
            fprintf(f,"%s\n",str.c_str());
        fprintf(f,"//***********************************\n");
    }

    fclose(f);
}

int main(int argc, char *argv[])
{
    wxInitializer initializer;

    wxCmdLineParser CmdLineParser(argc, argv);
    CmdLineParser.AddParam("DIRNAME",wxCMD_LINE_VAL_STRING,wxCMD_LINE_OPTION_MANDATORY);
    CmdLineParser.AddParam("TARGETFILE",wxCMD_LINE_VAL_STRING,wxCMD_LINE_PARAM_OPTIONAL);
    CmdLineParser.SetLogo("\nqdc: the \"quick and dirty coder\" from the Astade project (www.astade.tigris.org)\n"
        "Copyright (C) 2005  Thomas Spitzer and Anders Larsen\n\n"
        "This program is free software; you can redistribute it and/or modify\n"
        "it under the terms of the GNU General Public License as published by\n"
        "the Free Software Foundation; either version 2 of the License, or\n"
        "(at your option) any later version.\n\n"
        "This program is distributed in the hope that it will be useful,\n"
        "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
        "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
        "GNU General Public License for more details.\n\n"
        "You should have received a copy of the GNU General Public License\n"
        "along with this program; if not, write to the Free Software\n"
        "Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA\n\n"
        "To contact the author, mail to: author@astade.de\n\n");
    
    if (CmdLineParser.Parse()==0)
    {
        printf("Quick and Dirty Coder\n");
        dirname = argv[1];
        dirname.SetFullName("ModelNode.ini");
        int type=0;
        wxGetResource("Astade","Type",&type,dirname.GetFullPath());

        if ((0xFF00000 & type) == ITEM_IS_CLASS) 
        {
            wxChar* name = NULL;
            
            wxGetResource("Astade","Name", &name, dirname.GetFullPath());
            theClassname = name; 
            delete [] name;
            name = NULL;
            
            if (argc<3)
            {
                if (!wxGetResource("TreeView","ActiveComponent", &name, "Astade.ini"))
                    return EXIT_SUCCESS;
                theFileName = wxString(name);
                theFileName.AppendDir("auto");
                delete [] name;
                name = NULL;
                theFileName.SetName(theClassname);
            }
            else
            {
                theFileName = wxString(argv[2]);
            }        
    
            wxGetResource("Astade","AdditionalClasses", &name, dirname.GetFullPath());
            theAdditionalClasses = name; 
            delete [] name;
            name = NULL;
    
            doHpp();
            doCpp();
        }
        else
        {
            printf("Error: programm runs only in class directories\n");
        }        
    }
    return EXIT_SUCCESS;
}
