/* vi: set tabstop=4: */

std::set<wxString> filenames;

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
		const AdeRelation* pr = dynamic_cast<const AdeRelation*>(pe);
		assert(pr);
		wxFileName PartnerDir(pr->GetPartnerFile());
		PartnerDir.MakeAbsolute();
		wxFileName partner(PartnerDir);
		partner.RemoveDir(partner.GetDirCount()-1);
		partner.SetFullName("ModelNode.ini");
		const AdeModelElement* pe = AdeModelElement::CreateNewElement(partner);
		const AdeClass* pc = dynamic_cast<const AdeClass*>(pe);
		assert(pc);
		long RelationType = pr->GetType() & ITEM_RELATION_MASK;
		wxString RelationName(pr->GetName());
		wxString RelationImplementation(pr->GetImplementation());
 
		if (RelationType == ITEM_IS_GENERALIZATION)
		{
			if (BaseClasses)
			{
				if (!BaseClasses->empty())
					*BaseClasses += ", ";
				*BaseClasses += "public " + pc->GetName();
			}
		}

		if (RelationType == ITEM_IS_AGGREGATION ||
			RelationType == ITEM_IS_ASSOCIATION ||
			RelationType == ITEM_IS_COMPOSITION)
		{
			RelationTypes[RelationName] = RelationImplementation;
		}

		if ( spec && RelationType != ITEM_IS_IMPL_DEPENDENCY ||
			!spec && RelationType == ITEM_IS_IMPL_DEPENDENCY)
		{
			wxString PartnerClassname(pc->GetName());
			wxString PartnerHeadername = "\"" + PartnerClassname + ".h\"";

			wxString theClassInclude;
			if (pc->GetIsLibClass())
				theClassInclude = pc->GetLibClassInclude();
			if (theClassInclude.empty())
			{
				if (PartnerClassname != source->GetName())
					filenames.insert(PartnerHeadername);
			}
			else
			{
				InsertClassInclude(filenames, theClassInclude);
			}
        }
		delete pc;
    }
	delete pe;
    cont = dir.GetNext(&filename);
}

std::set<wxString>::iterator it;

if (!filenames.empty())
	out << "// Relation includes:" << std::endl;

for (it = filenames.begin(); it != filenames.end(); ++it)
	out << "#include " << (*it) << std::endl;
out << std::endl;
