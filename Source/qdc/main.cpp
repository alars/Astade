#include <cstdlib>
#include <iostream>
#include <map>
#include <wx/app.h>
#include <wx/dir.h>
#include <wx/filename.h>
#include <wx/string.h>
#include <wx/utils.h>
#include "../treeview/AstadeDef.h"

wxString theClassname;
wxFileName dirname;
std::map<wxString,wxString> memberDefaults;
std::map<wxString,wxString> RelationTypes;

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
     
    wxDir dir(attributes.GetPath());
    if (dir.Exists(attributes.GetPath()))
    {
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
                
                if (Static=="yes")
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
    
    for (it=attributenames.begin();it!=attributenames.end();++it)
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
     
    wxDir dir(attributes.GetPath());
    if (dir.Exists(attributes.GetPath()))
    {
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
    
    for (it=attributenames.begin();it!=attributenames.end();++it)
    {
        if (!spec)
            fprintf(f,"\t%s\t%s;\n",(*it).second.c_str(),(*it).first.c_str());
    }   
}

void operations(FILE* f, bool spec, int visibility)
{
    std::map<wxString,wxString> operationnames;
    std::map<wxString,wxString> operationtypes;
    std::map<wxString,bool> operationvirtuel;
    std::map<wxString,bool> operationabstract;
    std::map<wxString,bool> operationconst;
    std::map<wxString,bool> operationstatic;

    wxFileName operation(dirname);
    operation.AppendDir("operations");
     
    wxDir dir(operation.GetPath());
    if (dir.Exists(operation.GetPath()))
    {
        wxString filename;
        
        bool cont = dir.GetFirst(&filename,wxEmptyString,wxDIR_DIRS);
        while ( cont )
        {
            wxFileName FullName = operation;
            FullName.AppendDir(filename);
            
            FullName.SetFullName("Desktop.ini");
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
                operationtypes[FullName.GetFullPath()] = CodingType;
                if (Virtual=="yes")
                    operationvirtuel[FullName.GetFullPath()] = true;
                if (Abstract=="yes")
                    operationabstract[FullName.GetFullPath()] = true;
                if (Static=="yes")
                    operationstatic[FullName.GetFullPath()] = true;
                if (Const=="yes")
                    operationconst[FullName.GetFullPath()] = true;
            }    
            cont = dir.GetNext(&filename);
        }    
    }
    
    std::map<wxString,wxString>::iterator it;
    
    for (it=operationnames.begin();it!=operationnames.end();++it)
    {
        if (spec)
        {
            fprintf(f,"\n");
            
            fprintf(f,"%s\t%s::%s()\n{\n",operationtypes[(*it).first].c_str(),theClassname.c_str(),(*it).second.c_str());
            fprintf(f,"};\n");
        }
        else    
        {
            fprintf(f,"\t%s\t%s();\n",operationtypes[(*it).first].c_str(),(*it).second.c_str());
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
            wxGetResource("Relation","PartnerPath",&name,FullName.GetFullPath());
            wxFileName PartnerDir(name);
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
            
            if ((RelationType=="Agregation") || 
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
                partnerName.SetName("Desktop"); 
                partnerName.SetExt("ini");
                wxGetResource("Astade","Name", &name, partnerName.GetFullPath());
                wxString PartnerClassname(name);
                delete [] name;
                name = NULL;
                wxString PartnerHeadername = PartnerClassname + ".h";
                partnerName.SetFullName(PartnerHeadername);
                
                partnerName.MakeRelativeTo(dirname.GetPath());
                
                if (PartnerClassname!=theClassname)
                    filenames[partnerName.GetFullPath()] = true;
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
    wxFileName theFileName = dirname;
    theFileName.SetName(theClassname);
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
    
    RelationIncludes(f,false);    
    
    fprintf(f,"class %s\n{\n",theClassname.c_str());
    fprintf(f,"\tpublic:\n",theClassname.c_str());
    staticAttribute(f,false,ITEM_IS_PUBLIC);
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
    
    fprintf(f,"#endif\n");
    fclose(f);
}

void doCpp()
{
    FILE* f;
    wxFileName theFileName = dirname;
    theFileName.SetName(theClassname);
    theFileName.SetExt("cpp");
    f = fopen(theFileName.GetFullPath().c_str(),"w");
    fprintf(f,"//******************************************************\n");
    fprintf(f,"//** Coding is done with Astade Quick and Dirty Coder **\n");
    fprintf(f,"//** Filename: %-39s**\n",theFileName.GetFullName().c_str());
    fprintf(f,"//******************************************************\n\n");
    
    theFileName.SetExt("h");
    theFileName.MakeRelativeTo(dirname.GetPath());
    fprintf(f,"#include %s // own header\n\n",theFileName.GetFullPath().c_str());
    
    RelationIncludes(f,true);    
    staticAttribute(f,true,ITEM_IS_PUBLIC);
    staticAttribute(f,true,ITEM_IS_PROTECTED);
    staticAttribute(f,true,ITEM_IS_PRIVATE);
    operations(f,true,ITEM_IS_PUBLIC);
    operations(f,true,ITEM_IS_PROTECTED);
    operations(f,true,ITEM_IS_PRIVATE);
    
    fclose(f);
}

int main(int argc, char *argv[])
{
    wxInitializer initializer;
    if (argc!=2)
    {
        printf("Call the programm with the target dir:\n");
        printf("QDC <path>\n");
    } 
    else
    {
        printf("Quick and Dirty Coder\n");
        dirname = argv[1];
        dirname.SetFullName("Desktop.ini");
        int type=0;
        wxGetResource("Astade","Type",&type,dirname.GetFullPath());

        if ((0xFF00000 & type) == ITEM_IS_CLASS) 
        {
            wxChar* name = NULL;
            wxGetResource("Astade","Name", &name, dirname.GetFullPath());
            theClassname = name; 
            delete [] name;
    
            doHpp();
            doCpp();
        }
        else
        {
            printf("Programm runs only in Class Directories\n");
        }        
    }
    
    //while (true);
    return EXIT_SUCCESS;
}
