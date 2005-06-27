#include <cstdlib>
#include <iostream>
#include <wx/string.h>
#include <wx/dir.h>
#include <wx/filename.h>
#include <map>
#include "../treeview/AstadeDef.h"

wxString theClassname;
wxFileName dirname;

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
    while (true);
    
    return EXIT_SUCCESS;
}
