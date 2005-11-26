#include <cstdlib>
#include <iostream>
#include <map>
#include <wx/app.h>
#include <wx/dir.h>
#include <wx/filename.h>
#include <wx/string.h>
#include <wx/utils.h>
#include <wx/cmdline.h>

#include "../include/AdeDefines.h"

#ifdef __WXGTK__
WXDLLEXPORT bool wxGetResource(const wxString& section, const wxString& entry, wxChar **value, const wxString& file = wxEmptyString);
WXDLLEXPORT bool wxGetResource(const wxString& section, const wxString& entry, float *value, const wxString& file = wxEmptyString);
WXDLLEXPORT bool wxGetResource(const wxString& section, const wxString& entry, long *value, const wxString& file = wxEmptyString);
WXDLLEXPORT bool wxGetResource(const wxString& section, const wxString& entry, int *value, const wxString& file = wxEmptyString);
#endif

std::map<wxString,bool> nodelist;

void Listnodes(int depth, const char* Parentname,const char* pathname)
{
    wxFileName dirname(pathname);
    dirname.SetFullName("ModelNode.ini");
    int type = 0;
    wxGetResource("Astade","Type",&type,dirname.GetFullPath());
    if ((0xFF00000 & type) == ITEM_IS_CLASS) 
    {
        wxChar* name = NULL;
        wxGetResource("Astade","Name", &name, dirname.GetFullPath());
        wxString prename;
        
        if (strlen(Parentname))
        {
            prename = Parentname;
            prename = prename +":"+name;
        }
        else
            prename = name; 
        delete [] name;

        for (int i=0;i<depth;++i)
            printf("\t");
            
        wxString nodename = dirname.GetDirs()[dirname.GetDirCount()-1];
        nodelist[nodename] = true;
        
        printf("%s [label=\"%s\", style=filled, fillcolor=grey95, color=black];\n",dirname.GetDirs()[dirname.GetDirCount()-1].c_str(),prename.c_str());

        wxString filename;
        wxDir dir(dirname.GetPath());

        bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_DIRS);
        while ( cont )
        {
            wxFileName FullName = dirname;
            FullName.AppendDir(filename);
            Listnodes(depth,prename.c_str(),FullName.GetFullPath().c_str());
            cont = dir.GetNext(&filename);
        }
    }    
    
    if ((0xFF00000 & type) == ITEM_IS_CLASSES) 
    {
        wxString filename;
        wxDir dir(dirname.GetPath());
    
        bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_DIRS);
        while ( cont )
        {
            wxFileName FullName = dirname;
            FullName.AppendDir(filename);
            Listnodes(depth,Parentname,FullName.GetFullPath().c_str());
            cont = dir.GetNext(&filename);
        }
    }    

    if ((0xFF00000 & type) == ITEM_IS_PACKAGE) 
    {
        wxString filename;
        wxDir dir(dirname.GetPath());
    
        for (int i=0;i<depth;++i)
            printf("\t");
            
        printf("subgraph cluster%s {\n",dirname.GetDirs()[dirname.GetDirCount()-1].c_str());

        wxChar* name = NULL;
        wxGetResource("Astade","Name", &name, dirname.GetFullPath());
        for (int i=0;i<depth+1;++i)
            printf("\t");
        printf("label = \"Package: %s\", fontname=arial, fontsize=10, color=red\n",name);
        delete [] name;
        
        bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_DIRS);
        while ( cont )
        {
            wxFileName FullName = dirname;
            FullName.AppendDir(filename);
            Listnodes(depth+1,Parentname,FullName.GetFullPath().c_str());
            cont = dir.GetNext(&filename);
        }
        for (int i=0;i<depth;++i)
            printf("\t");
            
        printf("}\n");
     }    
}    
void ListEdges(const char* inClass, const char* pathname)
{
    wxFileName dirname(pathname);
    dirname.SetFullName("ModelNode.ini");
    int type=0;
    wxGetResource("Astade","Type",&type,dirname.GetFullPath());
    if (((0xFF00000 & type) == ITEM_IS_CLASS) ||
        ((0xFF00000 & type) == ITEM_IS_CLASSES) ||
        ((0xFF00000 & type) == ITEM_IS_PACKAGE) )
         
    {
        wxString activeElement = dirname.GetDirs()[dirname.GetDirCount()-1];
               
        wxString filename;
        wxDir dir(dirname.GetPath());
        bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_DIRS);
        while ( cont )
        {
            wxFileName FullName = dirname;
            FullName.AppendDir(filename);
            ListEdges(activeElement.c_str(),FullName.GetFullPath().c_str());
            cont = dir.GetNext(&filename);
        }
    }    
   
    if ((0xFF00000 & type) == ITEM_IS_RELATIONS)
    {
        wxString filename;
        wxDir dir(dirname.GetPath());
        bool cont = dir.GetFirst(&filename, "*.ini");
        while ( cont )
        {
            wxFileName FullName = dirname;
            FullName.SetFullName(filename);
            wxGetResource("Astade","Type",&type,FullName.GetFullPath());
            if ((0xFF00000 & type) == ITEM_IS_RELATION)
            {
                wxChar* name = NULL;
                wxGetResource("Astade","RelationType",&name,FullName.GetFullPath());
                wxFileName CodingType(name);
                delete [] name;
                name = NULL;
                wxGetResource("Astade","Name",&name,FullName.GetFullPath());
                wxString Label(name);
                delete [] name;
                name = NULL;
                wxGetResource("Astade","Multiplicity",&name,FullName.GetFullPath());
                wxString Multiplicity(name);
                delete [] name;
                name = NULL;
                wxGetResource("Astade","PartnerPath",&name,FullName.GetFullPath());
                wxFileName PartnerDir(name);
		PartnerDir.MakeAbsolute();
                delete [] name;
                name = NULL;
                if (nodelist.find(PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2])==nodelist.end())
                {
                    wxFileName partnerName(PartnerDir);
                    int i = partnerName.GetDirCount();
                    partnerName.RemoveDir(i-1);
                    partnerName.SetName("ModelNode");
                    partnerName.SetExt("ini");
                    wxGetResource("Astade","Name", &name, partnerName.GetFullPath());
                          
                    printf("%s [label=\"%s\", color=black];\n",PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2].c_str(),name);
                    delete [] name;
                    name = NULL;
                }    

            	if (CodingType=="ImplementationDependency")
                    printf("\"%s\" -> \"%s\" [label=\"%s\", fontname=arial, fontsize=10, color=blue, style=dashed, arrowhead=vee];\n",inClass,PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2].c_str(),"<<uses>>");
            	
            	if (CodingType=="SpecificationDependency")
                    printf("\"%s\" -> \"%s\" [label=\"%s\", fontname=arial, fontsize=10,  color=blue, style=dashed, arrowhead=vee];\n",inClass,PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2].c_str(),"<<uses>>");
            	
            	if (CodingType=="Association")
                    printf("\"%s\" -> \"%s\" [label=\"%s\", headlabel=\"%s\", fontname=arial, fontsize=10,  color=red, arrowhead=vee];\n",inClass,PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2].c_str(),Label.c_str(),Multiplicity.c_str());
            	
            	if (CodingType=="Agregation")
                    printf("\"%s\" -> \"%s\" [label=\"%s\", headlabel=\"%s\", fontname=arial, fontsize=10,  color=red, arrowtail=odiamond, arrowhead=none];\n",inClass,PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2].c_str(),Label.c_str(),Multiplicity.c_str());
            	
            	if (CodingType=="Composition")
                    printf("\"%s\" -> \"%s\" [label=\"%s\", headlabel=\"%s\", fontname=arial, fontsize=10,  color=red, arrowtail=diamond, arrowhead=none];\n",inClass,PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2].c_str(),Label.c_str(),Multiplicity.c_str());
            	
            	if (CodingType=="Generalization")
                    printf("\"%s\" -> \"%s\" [color=blue, fontname=arial, fontsize=10,  arrowhead=onormal];\n",inClass,PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2].c_str());

                delete [] name;
            }    
            cont = dir.GetNext(&filename);
        }
    }    
}    

int main(int argc, char *argv[])
{
    wxInitializer initializer;
    wxCmdLineParser CmdLineParser(argc, argv);
    CmdLineParser.AddParam("DIRNAME",wxCMD_LINE_VAL_STRING,wxCMD_LINE_OPTION_MANDATORY);
    CmdLineParser.SetLogo("\nomd: the \"object model diagram (creator)\" from the Astade project (www.astade.tigris.org)\n"
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
       printf("digraph G {\n");
        printf("\tnode [shape=box, fontname=arial, fontsize=12]\n");
        Listnodes(1,"",argv[1]);
        ListEdges("",argv[1]);
        printf("}\n");
    }       
    return EXIT_SUCCESS;
}
