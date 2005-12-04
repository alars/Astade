wxFileName dirname(path);
dirname.SetFullName("ModelNode.ini");
int type = 0;
wxGetResource("Astade","Type",&type,dirname.GetFullPath());
if (((0xFF00000 & type) == ITEM_IS_CLASS) ||
    ((0xFF00000 & type) == ITEM_IS_CLASSES) ||
    ((0xFF00000 & type) == ITEM_IS_PACKAGE) )
{
	wxString activeElement(dirname.GetDirs()[dirname.GetDirCount()-1]);
	wxString filename;
	wxDir dir(dirname.GetPath());
	bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_DIRS);
	while (cont)
	{
		wxFileName FullName(dirname);
		FullName.AppendDir(filename);
		ListEdges(activeElement.c_str(), FullName.GetFullPath().c_str());
		cont = dir.GetNext(&filename);
	}
}    
   
if ((0xFF00000 & type) == ITEM_IS_RELATIONS)
{
	wxString filename;
	wxDir dir(dirname.GetPath());
	bool cont = dir.GetFirst(&filename, "*.ini");
	while (cont)
	{
		wxFileName FullName(dirname);
		FullName.SetFullName(filename);
		wxGetResource("Astade", "Type", &type, FullName.GetFullPath());
		if ((0xFF00000 & type) == ITEM_IS_RELATION)
		{
			wxChar* name = NULL;
			wxGetResource("Astade", "RelationType", &name, FullName.GetFullPath());
			wxFileName CodingType(name);
			delete [] name;
			name = NULL;
			wxGetResource("Astade", "Name", &name, FullName.GetFullPath());
			wxString Label(name);
			delete [] name;
			name = NULL;
			wxGetResource("Astade", "Multiplicity", &name, FullName.GetFullPath());
			wxString Multiplicity(name);
			delete [] name;
			name = NULL;
			wxGetResource("Astade", "PartnerPath", &name, FullName.GetFullPath());
			wxFileName PartnerDir(name);
			PartnerDir.MakeAbsolute();
			delete [] name;
			name = NULL;
			if (nodelist.find(PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2]) == nodelist.end())
			{
				wxFileName partnerName(PartnerDir);
				int i = partnerName.GetDirCount();
				partnerName.RemoveDir(i-1);
				partnerName.SetName("ModelNode");
				partnerName.SetExt("ini");
				wxGetResource("Astade", "Name", &name, partnerName.GetFullPath());
                          
				printf("%s [label=\"%s\", color=black];\n", PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2].c_str(), name);
				delete [] name;
				name = NULL;
			}    

			if (CodingType == "ImplementationDependency")
				printf("\"%s\" -> \"%s\" [label=\"%s\", fontname=arial, fontsize=10, color=blue, style=dashed, arrowhead=vee];\n", inClass, PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2].c_str(), "<<uses>>");

			if (CodingType == "SpecificationDependency")
				printf("\"%s\" -> \"%s\" [label=\"%s\", fontname=arial, fontsize=10, color=blue, style=dashed, arrowhead=vee];\n", inClass, PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2].c_str(), "<<uses>>");

			if (CodingType == "Association")
				printf("\"%s\" -> \"%s\" [label=\"%s\", headlabel=\"%s\", fontname=arial, fontsize=10, color=red, arrowhead=vee];\n", inClass, PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2].c_str(), Label.c_str(), Multiplicity.c_str());

			if (CodingType == "Agregation")
				printf("\"%s\" -> \"%s\" [label=\"%s\", headlabel=\"%s\", fontname=arial, fontsize=10, color=red, arrowtail=odiamond, arrowhead=none];\n", inClass, PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2].c_str(), Label.c_str(), Multiplicity.c_str());

			if (CodingType == "Composition")
				printf("\"%s\" -> \"%s\" [label=\"%s\", headlabel=\"%s\", fontname=arial, fontsize=10, color=red, arrowtail=diamond, arrowhead=none];\n", inClass, PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2].c_str(), Label.c_str(), Multiplicity.c_str());

			if (CodingType == "Generalization")
				printf("\"%s\" -> \"%s\" [color=blue, fontname=arial, fontsize=10, arrowhead=onormal];\n", inClass, PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2].c_str());

			delete [] name;
		}
		cont = dir.GetNext(&filename);
	}
} 
