wxFileName path = pe->GetFileName();
if ((pe->GetType() & 0x0ff00000) == ITEM_IS_CLASS ||
    (pe->GetType() & 0x0ff00000) == ITEM_IS_CLASSES ||
    (pe->GetType() & 0x0ff00000) == ITEM_IS_PACKAGE)
{
	wxString activeElement(path.GetDirs()[path.GetDirCount()-1]);
	AdeDirectoryElement de(path);
	for (AdeElementIterator eit = de.begin(); eit != de.end(); ++eit)
	{
		AdeModelElement* pme = eit.CreateNewElement();
		ListEdges(activeElement, pme);
		delete pme;
	}
}
else if ((pe->GetType() & 0x0ff00000) == ITEM_IS_RELATIONS)
{
	AdeDirectoryElement de(path);
	for (AdeElementIterator eit = de.begin(); eit != de.end(); ++eit)
	{
		AdeModelElement* pme = eit.CreateNewElement();
		ListEdges(inClass, pme);
		delete pme;
	}
}
else if ((pe->GetType() & 0x0ff00000) == ITEM_IS_RELATION)
{
	const AdeRelation* pr = dynamic_cast<const AdeRelation*>(pe);
	if (!pr)
		return;

	wxFileName PartnerDir = pr->GetPartnerFile();
	PartnerDir.MakeAbsolute();
	if (nodelist.find(PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2]) == nodelist.end())
	{
		wxFileName partner(PartnerDir);
		partner.RemoveDir(partner.GetDirCount()-1);
		partner.SetFullName("ModelNode.ini");
		AdeModelElement me(partner);
		printf("%s [label=\"%s\", color=black];\n", PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2].c_str(), me.GetName().c_str());
	}

	switch (pr->GetType() & 0xff)
	{
		case 5:
			printf("\"%s\" -> \"%s\" [label=\"%s\", fontname=arial, fontsize=10, color=blue, style=dashed, arrowhead=vee];\n",
				inClass.c_str(),
				PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2].c_str(),
				"<<uses>>");
			break;

		case 4:
			printf("\"%s\" -> \"%s\" [label=\"%s\", fontname=arial, fontsize=10, color=blue, style=dashed, arrowhead=vee];\n",
				inClass.c_str(),
				PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2].c_str(),
				"<<uses>>");
			break;

		case 3:
			printf("\"%s\" -> \"%s\" [label=\"%s\", headlabel=\"%s\", fontname=arial, fontsize=10, color=red, arrowhead=vee];\n",
				inClass.c_str(),
				PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2].c_str(),
				pr->AdeModelElement::GetName().c_str(),
				pr->GetMultiplicity().c_str());
			break;

		case 2:
			printf("\"%s\" -> \"%s\" [label=\"%s\", headlabel=\"%s\", fontname=arial, fontsize=10, color=red, arrowtail=odiamond, arrowhead=none];\n",
				inClass.c_str(),
				PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2].c_str(),
				pr->AdeModelElement::GetName().c_str(),
				pr->GetMultiplicity().c_str());
			break;

		case 1:
			printf("\"%s\" -> \"%s\" [label=\"%s\", headlabel=\"%s\", fontname=arial, fontsize=10, color=red, arrowtail=diamond, arrowhead=none];\n",
				inClass.c_str(),
				PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2].c_str(),
				pr->AdeModelElement::GetName().c_str(),
				pr->GetMultiplicity().c_str());
			break;

		case 0:
			printf("\"%s\" -> \"%s\" [color=blue, fontname=arial, fontsize=10, arrowhead=onormal];\n",
				inClass.c_str(),
				PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2].c_str());
			break;
	}
}
