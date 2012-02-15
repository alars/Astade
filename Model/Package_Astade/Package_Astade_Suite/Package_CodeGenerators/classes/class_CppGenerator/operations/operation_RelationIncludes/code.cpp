//~~ void RelationIncludes(std::ofstream& out, bool spec, wxString* BaseClasses) [CppGenerator] ~~

std::set<wxString, AdeStringCompare> filenames;
std::set<wxString, AdeStringCompare> baseclasses;
std::set<const AdeClass*, AdeElementCompare> classes;

wxFileName relations(source->GetFileName());
relations.AppendDir(wxS("relations"));

wxDir dir(relations.GetPath());
wxString filename;

bool cont = dir.GetFirst(&filename, wxS("*.ini"));
while (cont)
{
    wxFileName FullName(relations);
    FullName.SetFullName(filename);
	const AdeModelElement* pe = AdeModelElement::CreateNewElement(FullName);
	if ((pe->GetType() & ITEM_TYPE_MASK) == ITEM_IS_RELATION)
	{
		bool keeprelation = false;
		bool keepclass    = false;
		const AdeRelation* pr = dynamic_cast<const AdeRelation*>(pe);
		assert(pr);
		long RelationType = pr->GetType() & ITEM_RELATION_MASK;
		const AdeClass* pc = dynamic_cast<const AdeClass*>(pr->GetPartner());
		if (spec && (RelationType == ITEM_IS_AGGREGATION ||
					 RelationType == ITEM_IS_ASSOCIATION ||
					 RelationType == ITEM_IS_COMPOSITION))
		{
			Relations.insert(pr);
			keeprelation = true;
		}

		if (pc && pc->GetName() != source->GetName())
		{
			wxString relNamespace(getNamespace(getRelativeNamespace(pc)));
			if (RelationType == ITEM_IS_GENERALIZATION)
			{
				// test whether there is an inheritance from a statechart,
				// because we have to insert some macros, later.
				if (dynamic_cast<const AdeStatechart*>(pc) != 0)
					inheritsFromStatechart = true;
				wxString base_class(relNamespace + pc->GetName());
				if (!pr->GetTemplateString().empty())
					base_class += wxS("<") + pr->GetTemplateString() + wxS(">");
				baseclasses.insert(base_class);
			}

			enum { _NOTHING, _INCLUDE, _FORWARD } mode = _NOTHING;
			if (spec && RelationType != ITEM_IS_IMPL_DEPENDENCY &&
						RelationType != ITEM_IS_FRIEND)
			{
				if (RelationType == ITEM_IS_SPEC_DEPENDENCY ||
					pc->IsLibClass()                        ||
					RelationType == ITEM_IS_GENERALIZATION  ||
					(RelationType == ITEM_IS_COMPOSITION &&
					 pr->GetImplementation().Find('*') == wxNOT_FOUND))
					mode = _INCLUDE;
				else
					mode = _FORWARD;
			}
			if (!spec && RelationType != ITEM_IS_SPEC_DEPENDENCY)
			{
				if (RelationType == ITEM_IS_IMPL_DEPENDENCY ||
					(!pc->IsLibClass() &&
					 (RelationType == ITEM_IS_AGGREGATION ||
					  RelationType == ITEM_IS_ASSOCIATION ||
					  (RelationType == ITEM_IS_COMPOSITION &&
					   pr->GetImplementation().Find('*') != wxNOT_FOUND))))
					mode = _INCLUDE;
			}

			wxString theClassInclude;
			wxString PartnerHeader = wxS("\"") + pc->GetName() + wxS(".h\"");
			switch (mode)
			{
				case _NOTHING:
					break;

				case _INCLUDE:
					if (pc->IsLibClass())
						theClassInclude = pc->GetLibClassInclude();
					if (theClassInclude.empty())
						filenames.insert(PartnerHeader);
					else
						InsertClassInclude(filenames, theClassInclude);
					break;

				case _FORWARD:
					classes.insert(pc);
					keepclass = true;
					break;
			}
        }
		if (!keepclass)
			delete pc;
		if (!keeprelation)
			delete pr;
    }
	else
		delete pe;
    cont = dir.GetNext(&filename);
}

std::set<wxString>::iterator it;

if (!filenames.empty())
{
	out << "// Relation includes:" << std::endl;
	for (it = filenames.begin(); it != filenames.end(); ++it)
		out << "#include " << *it << std::endl;
}
out << std::endl;

if (!classes.empty())
{
	std::set<const AdeClass*>::iterator it;
	out << "// Relation forward declarations:" << std::endl;
	for (it = classes.begin(); it != classes.end(); ++it)
	{
		const AdeClass* pc = *it;
		wxArrayString theNamespace(pc->getNamespace());
		for (unsigned int ix = 0; ix < theNamespace.GetCount(); ++ix)
			out << "namespace "
				<< theNamespace[ix]
				<< " {"
				<< std::endl;
		out << "class "
			<< pc->GetLabel()
			<< ";"
			<< std::endl;
		for (unsigned int ix = theNamespace.GetCount(); ix-- > 0; )
		    out << "} // namespace "
				<< theNamespace[ix]
				<< std::endl;
		delete pc;
	}
}

if (BaseClasses && !baseclasses.empty())
{
	for (it = baseclasses.begin(); it != baseclasses.end(); ++it)
	{
		if (!BaseClasses->empty())
			*BaseClasses += wxS(", ");
		*BaseClasses += wxS("public ") + *it;
	}
}
out << std::endl;
