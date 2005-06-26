#include <cstdlib>
#include <iostream>
#include <wx/string.h>
#include <wx/filename.h>
#include "../treeview/AstadeDef.h"

wxString theClassname;
wxFileName dirname;

void findOutClassname()
{
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
