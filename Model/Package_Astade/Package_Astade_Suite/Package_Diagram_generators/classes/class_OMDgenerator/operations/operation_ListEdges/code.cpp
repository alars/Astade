//~~ void ListEdges(const wxString inClass, const AdeModelElement* pe) [OMDgenerator] ~~

wxFileName path = pe->GetFileName();
if ((pe->GetType() & ITEM_TYPE_MASK) == ITEM_IS_CLASS ||
    (pe->GetType() & ITEM_TYPE_MASK) == ITEM_IS_CLASSES ||
    (pe->GetType() & ITEM_TYPE_MASK) == ITEM_IS_PACKAGE)
{
	if ((pe->GetType() & ITEM_TYPE_MASK) == ITEM_IS_CLASS)
	{
		const AdeClass* pc = dynamic_cast<const AdeClass*>(pe);
		assert(pc);
		if (!showall && !pc->IsInActiveComponent())
			return;
	}
	wxString activeElement(path.GetDirs()[path.GetDirCount()-1]);
	AdeDirectoryElement de(path);
	for (AdeElementIterator eit = de.begin(); eit != de.end(); ++eit)
	{
		AdeModelElement* pme = eit.CreateNewElement();
		ListEdges(activeElement, pme);
		delete pme;
	}
}
else if ((pe->GetType() & ITEM_TYPE_MASK) == ITEM_IS_RELATIONS)
{
	AdeDirectoryElement de(path);
	for (AdeElementIterator eit = de.begin(); eit != de.end(); ++eit)
	{
		AdeModelElement* pme = eit.CreateNewElement();
		ListEdges(inClass, pme);
		delete pme;
	}
}
else if ((pe->GetType() & ITEM_TYPE_MASK) == ITEM_IS_RELATION)
{
	const AdeRelation* pr = dynamic_cast<const AdeRelation*>(pe);
	assert(pr);
	std::cout << std::endl;
	wxFileName PartnerDir = pr->GetPartnerFile();
	wxString PartnerClass(PartnerDir.GetDirs()[PartnerDir.GetDirCount()-2]);
	if (nodelist.find(PartnerClass) == nodelist.end())
	{
		if (!showext)
			return;
		wxFileName partner(PartnerDir);
		partner.RemoveDir(partner.GetDirCount()-1);
		partner.SetFullName(wxS("ModelNode.ini"));
		AdeModelElement me(partner);
		std::cout << '\t'
			<< CleanName(PartnerClass).utf8_str()
			<< " [label=\"";
		if ((me.GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATECHART)
			std::cout << "\\«statechart\\»\\n";
		std::cout << me.GetName().utf8_str()
			<< "\", color=black];"
			<< std::endl;
	}

	switch (pr->GetType() & ITEM_RELATION_MASK)
	{
		case ITEM_IS_GENERALIZATION:
			std::cout << '\t'
				<< CleanName(inClass).utf8_str()
				<< " -> "
				<< CleanName(PartnerClass).utf8_str();
			if (!pr->GetTemplateString().empty())
			{
				std::cout
					<< " [label=\""
					<< "<"
					<< pr->GetTemplateString().utf8_str()
					<< ">"
					<< "\",";
			}
			else
			{
				std::cout << " [label=\"\",";
			}
			std::cout
			<< " fontname=Helvetica, fontsize=10, color=blue, arrowhead=onormal];"
			<< std::endl;
			break;

		case ITEM_IS_COMPOSITION:
			std::cout << '\t'
				<< CleanName(inClass).utf8_str()
				<< " -> "
				<< CleanName(PartnerClass).utf8_str()
				<< " [label=\""
				<< pr->GetName().utf8_str()
				<< "\", headlabel=\""
				<< pr->GetMultiplicity().utf8_str()
				<< "\", fontname=Helvetica, fontsize=10, color=red, arrowhead=vee, arrowtail=diamond, dir=both];"
				<< std::endl;
			break;

		case ITEM_IS_AGGREGATION:
			std::cout << '\t'
				<< CleanName(inClass).utf8_str()
				<< " -> "
				<< CleanName(PartnerClass).utf8_str()
				<< " [label=\""
				<< pr->GetName().utf8_str()
				<< "\", headlabel=\""
				<< pr->GetMultiplicity().utf8_str()
				<< "\", fontname=Helvetica, fontsize=10, color=red, arrowhead=vee, arrowtail=odiamond, dir=both];"
				<< std::endl;
			break;

		case ITEM_IS_ASSOCIATION:
			std::cout << '\t'
				<< CleanName(inClass).utf8_str()
				<< " -> "
				<< CleanName(PartnerClass).utf8_str()
				<< " [label=\""
				<< pr->GetName().utf8_str()
				<< "\", headlabel=\""
				<< pr->GetMultiplicity().utf8_str()
				<< "\", fontname=Helvetica, fontsize=10, color=red, arrowhead=vee];"
				<< std::endl;
			break;

		case ITEM_IS_SPEC_DEPENDENCY:
		case ITEM_IS_IMPL_DEPENDENCY:
			std::cout << '\t'
				<< CleanName(inClass).utf8_str()
				<< " -> "
				<< CleanName(PartnerClass).utf8_str()
				<< " [label=\"\\«use\\»\", fontname=Helvetica, fontsize=10, color=blue, style=dashed, arrowhead=vee];"
				<< std::endl;
			break;

		case ITEM_IS_FRIEND:
			std::cout << '\t'
				<< CleanName(inClass).utf8_str()
				<< " -> "
				<< CleanName(PartnerClass).utf8_str()
				<< " [label=\"\\«friend\\»\", fontname=Helvetica, fontsize=10, color=blue, style=dashed, arrowhead=vee];"
				<< std::endl;
			break;

		default:
			std::cout << '\t'
				<< CleanName(inClass).utf8_str()
				<< " -> "
				<< CleanName(PartnerClass).utf8_str()
				<< " [fontname=Helvetica, fontsize=10, color=blue, style=dashed, arrowhead=vee];"
				<< std::endl;
			break;
	}
}
