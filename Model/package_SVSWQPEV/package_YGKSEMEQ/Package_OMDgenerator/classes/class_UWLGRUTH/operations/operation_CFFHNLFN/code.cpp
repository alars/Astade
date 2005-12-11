// vi: set tabstop=4:
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

	std::cout << std::endl;
	wxFileName PartnerDir = pr->GetPartnerFile();
	PartnerDir.MakeAbsolute();
	wxString PartnerClass(PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2]);
	if (nodelist.find(PartnerClass) == nodelist.end())
	{
		if (onlylocal)
			return;
		wxFileName partner(PartnerDir);
		partner.RemoveDir(partner.GetDirCount()-1);
		partner.SetFullName("ModelNode.ini");
		AdeModelElement me(partner);
		std::cout << '\t'
			<< PartnerClass
			<< " [label=\""
			<< me.GetName()
			<< "\", color=black];"
			<< std::endl;
	}

	switch (pr->GetType() & 0xff)
	{
		case 0:
			std::cout << '\t'
				<< inClass
				<< " -> "
				<< PartnerClass
				<< " [fontname=Helvetica, fontsize=10, color=blue, arrowhead=onormal];"
				<< std::endl;
			break;

		case 1:
			std::cout << '\t'
				<< inClass
				<< " -> "
				<< PartnerClass
				<< " [label=\""
				<< pr->AdeModelElement::GetName()
				<< "\", headlabel=\""
				<< pr->GetMultiplicity()
				<< "\", fontname=Helvetica, fontsize=10, color=red, arrowhead=none, arrowtail=diamond];"
				<< std::endl;
			break;

		case 2:
			std::cout << '\t'
				<< inClass
				<< " -> "
				<< PartnerClass
				<< " [label=\""
				<< pr->AdeModelElement::GetName()
				<< "\", headlabel=\""
				<< pr->GetMultiplicity()
				<< "\", fontname=Helvetica, fontsize=10, color=red, arrowhead=none, arrowtail=odiamond];"
				<< std::endl;
			break;

		case 3:
			std::cout << '\t'
				<< inClass
				<< " -> "
				<< PartnerClass
				<< " [label=\""
				<< pr->AdeModelElement::GetName()
				<< "\", headlabel=\""
				<< pr->GetMultiplicity()
				<< "\", fontname=Helvetica, fontsize=10, color=red, arrowhead=vee];"
				<< std::endl;
			break;

		case 4:
		case 5:
			std::cout << '\t'
				<< inClass
				<< " -> "
				<< PartnerClass
				<< " [label=\"<<use>>\", fontname=Helvetica, fontsize=10, color=blue, style=dashed, arrowhead=vee];"
				<< std::endl;
			break;
	}
}
