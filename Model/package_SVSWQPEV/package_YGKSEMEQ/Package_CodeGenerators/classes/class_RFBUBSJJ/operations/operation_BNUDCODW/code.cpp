/* vi: set tabstop=4: */

std::set<wxString, AdeStringCompare> filenames;
std::set<wxString, AdeStringCompare> classnames;
std::set<wxString, AdeStringCompare> baseclasses;

wxFileName relations(source->GetFileName());
relations.AppendDir("relations");

wxDir dir(relations.GetPath());
wxString filename;

bool cont = dir.GetFirst(&filename, "*.ini");
while (cont)
{
    wxFileName FullName(relations);
    FullName.SetFullName(filename);
	const AdeModelElement* pe = AdeModelElement::CreateNewElement(FullName);
	if ((pe->GetType() & ITEM_TYPE_MASK) == ITEM_IS_RELATION)
	{
		bool keep = false;
		const AdeRelation* pr = dynamic_cast<const AdeRelation*>(pe);
		assert(pr);
		long RelationType = pr->GetType() & ITEM_RELATION_MASK;
		wxFileName PartnerDir(pr->GetPartnerFile());
		wxFileName partner(PartnerDir);
		partner.RemoveDir(partner.GetDirCount()-1);
		partner.SetFullName("ModelNode.ini");
		const AdeModelElement* pe2 = AdeModelElement::CreateNewElement(partner);
		const AdeClass* pc = dynamic_cast<const AdeClass*>(pe2);
		if (spec && (RelationType == ITEM_IS_AGGREGATION ||
					 RelationType == ITEM_IS_ASSOCIATION ||
					 RelationType == ITEM_IS_COMPOSITION))
		{
			Relations.insert(pr);
			keep = true;
		}

		if (pc && pc->GetName() != source->GetName())
		{
			if (RelationType == ITEM_IS_GENERALIZATION)
			{
				// test whether there is an inheritance from a statechart,
				// because we have to insert some macros, later.
				if (dynamic_cast<const AdeStatechart*>(pe2) != 0)
					inheritsFromStatechart = true;
				wxString base_class(pc->GetName());
				if (!pr->GetTemplateString().empty())
					base_class += "<" + pr->GetTemplateString() + ">";
				baseclasses.insert(base_class);
			}

			enum { _NOTHING, _INCLUDE, _FORWARD } mode = _NOTHING;
			if (spec && RelationType != ITEM_IS_IMPL_DEPENDENCY &&
						RelationType != ITEM_IS_FRIEND)
			{
				if (RelationType == ITEM_IS_SPEC_DEPENDENCY ||
					pc->IsLibClass()                        ||
					RelationType == ITEM_IS_GENERALIZATION  ||
					RelationType == ITEM_IS_COMPOSITION &&
						pr->GetImplementation().Find('*') == wxNOT_FOUND)
					mode = _INCLUDE;
				else
					mode = _FORWARD;
			}
			if (!spec && RelationType != ITEM_IS_SPEC_DEPENDENCY)
			{
				if (RelationType == ITEM_IS_IMPL_DEPENDENCY ||
					!pc->IsLibClass() &&
					(RelationType == ITEM_IS_AGGREGATION ||
					 RelationType == ITEM_IS_ASSOCIATION ||
					 RelationType == ITEM_IS_COMPOSITION &&
						pr->GetImplementation().Find('*') != wxNOT_FOUND))
					mode = _INCLUDE;
			}

			wxString theClassInclude;
			wxString PartnerHeader = "\"" + pc->GetName() + ".h\"";
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
					classnames.insert(pc->GetName());
					break;
			}
        }
		delete pe2;
		if (!keep)
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
		out << "#include " << (const char*)(*it).c_str() << std::endl;
}
out << std::endl;

if (!classnames.empty())
{
	out << "// Relation forward declarations:" << std::endl;
	for (it = classnames.begin(); it != classnames.end(); ++it)
		out << "class " << (const char*)(*it).c_str() << ";" << std::endl;
}

if (BaseClasses && !baseclasses.empty())
{
	for (it = baseclasses.begin(); it != baseclasses.end(); ++it)
	{
		if (!BaseClasses->empty())
			*BaseClasses += ", ";
		*BaseClasses += "public " + *it;
	}
}
out << std::endl;
