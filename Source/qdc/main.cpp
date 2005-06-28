#include <cstdlib>
#include <iostream>
#include <wx/string.h>
#include <wx/dir.h>
#include <wx/filename.h>
#include <map>
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
            wxChar* name = new wxChar[200];
            int type;
            
            wxGetResource("Astade","Type",&type,FullName.GetFullPath());
            if (((0xFF00000 & type) == ITEM_IS_ATTRIBUTE) &&
                ((type & visibility) == visibility))
            {
                wxGetResource("Astade","Name",&name,FullName.GetFullPath());
                wxString theName(name);
                wxGetResource("Astade","CodingType",&name,FullName.GetFullPath());
                wxString CodingType(name);
                wxGetResource("Astade","Static",&name,FullName.GetFullPath());
                wxString Static(name);
                wxGetResource("Astade","Default",&name,FullName.GetFullPath());
                wxString Default(name);
                
                if (Static=="yes")
                {
                    attributenames[theName] = CodingType;
                    if (Default.size()>0)
                        attributedefaults[theName] = Decode(Default);
                }    
            }    
            delete [] name;
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
            wxChar* name = new wxChar[200];
            int type;
            
            wxGetResource("Astade","Type",&type,FullName.GetFullPath());
            if (((0xFF00000 & type) == ITEM_IS_ATTRIBUTE) &&
                ((type & visibility) == visibility))
            {
                wxGetResource("Astade","Name",&name,FullName.GetFullPath());
                wxString theName(name);
                wxGetResource("Astade","CodingType",&name,FullName.GetFullPath());
                wxString CodingType(name);
                wxGetResource("Astade","Static",&name,FullName.GetFullPath());
                wxString Static(name);
                wxGetResource("Astade","Default",&name,FullName.GetFullPath());
                wxString Default(name);
                
                if (Static!="yes")
                {
                    attributenames[theName] = CodingType;
                    if (Default.size()>0)
                        memberDefaults[theName] = Decode(Default);
                }    
            }    
            delete [] name;
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
        wxChar* name = new wxChar[200];
        int type;
        
        wxGetResource("Astade","Type",&type,FullName.GetFullPath());
        if ((0xFF00000 & type) == ITEM_IS_RELATION)
        {
            wxChar* name = new wxChar[2000];
            wxGetResource("Relation","PartnerPath",&name,FullName.GetFullPath());
            wxFileName PartnerDir(name);
            wxGetResource("Astade","RelationType",&name,FullName.GetFullPath());
            wxString RelationType(name);
            wxGetResource("Astade","Name",&name,FullName.GetFullPath());
            wxString RelationName(name);
            wxGetResource("Astade","Implementation",&name,FullName.GetFullPath());
            wxString RelationImplementation(name);
            
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
                wxString PartnerHeadername = PartnerClassname + ".h";
                partnerName.SetFullName(PartnerHeadername);
                
                partnerName.MakeRelativeTo(dirname.GetPath());
                
                if (PartnerClassname!=theClassname)
                    filenames[partnerName.GetFullPath()] = true;
            }    
        }    
        delete [] name;
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

    fprintf(f,"\n\tprotected:\n",theClassname.c_str());
    staticAttribute(f,false,ITEM_IS_PROTECTED);
    memberAttribute(f,false,ITEM_IS_PROTECTED);
    fprintf(f,"\n\t// Relations:\n",theClassname.c_str());
    
    std::map<wxString,wxString>::iterator it;
    
    for (it=RelationTypes.begin();it!=RelationTypes.end();++it)
    {
        fprintf(f,"\t%s\t%s;\n",(*it).second.c_str(),(*it).first.c_str());
    }   
    
    fprintf(f,"\n\tprivate:\n",theClassname.c_str());
    staticAttribute(f,false,ITEM_IS_PRIVATE);
    memberAttribute(f,false,ITEM_IS_PRIVATE);
    
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
    
    fclose(f);
}

int main(int argc, char *argv[])
{
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
            wxChar* name = new wxChar[200];
            wxGetResource("Astade","Name", &name, dirname.GetFullPath());
            theClassname = name; 
    
            doHpp();
            doCpp();
            
            delete [] name;
        }
        else
        {
            printf("Programm runs only in Class Directories\n");
        }        
    }
    
    return EXIT_SUCCESS;
}
