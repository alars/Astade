//~~ void RelationIncludes(std::ofstream& out, bool spec) [CGenerator] ~~

std::set<wxString, AdeStringCompare> filenames;

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
		bool keep = false;
		const AdeRelation* pr = dynamic_cast<const AdeRelation*>(pe);
		assert(pr);
		long RelationType = pr->GetType() & ITEM_RELATION_MASK;
		wxFileName PartnerDir(pr->GetPartnerFile());
		wxFileName partner(PartnerDir);
		partner.RemoveDir(partner.GetDirCount()-1);
		partner.SetFullName(wxS("ModelNode.ini"));
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
				baseClasses.insert(pc->GetName());
			}

			enum { _NOTHING, _INCLUDE } mode = _NOTHING;
			if (spec && RelationType != ITEM_IS_IMPL_DEPENDENCY &&
						RelationType != ITEM_IS_FRIEND)
			{
				mode = _INCLUDE;
			}

			if (!spec && RelationType == ITEM_IS_IMPL_DEPENDENCY)
			{
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

if (!filenames.empty())
{
	out << "// Relation includes:" << std::endl;
	for (std::set<wxString>::iterator it = filenames.begin(); it != filenames.end(); ++it)
		out << "#include " << it->utf8_str() << std::endl;
}
out << std::endl;
