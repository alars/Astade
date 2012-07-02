//~~ void memberType(std::ofstream& out) [CppGenerator] ~~

std::map<wxString, const AdeType*, AdeStringCompare> types;

wxFileName attributes(source->GetFileName());
attributes.AppendDir(wxS("types"));

if (wxDir::Exists(attributes.GetPath()))
{
	wxDir dir(attributes.GetPath());
	wxString filename;

	bool cont = dir.GetFirst(&filename, wxS("*.ini"));
	while (cont)
	{
		wxFileName FullName(attributes);
		FullName.SetFullName(filename);
		const AdeModelElement* pe = AdeModelElement::CreateNewElement(FullName);
		if ((pe->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TYPE)
		{
			const AdeType* pt = dynamic_cast<const AdeType*>(pe);
			assert(pt);
			types[pt->GetName()] = pt;
		}
		else
			delete pe;
		cont = dir.GetNext(&filename);
	}

	std::map<wxString, const AdeType*>::iterator it;
	for (it = types.begin(); it != types.end(); ++it)
	{
		const AdeType* pt = it->second;
		out << "/** " << pt->GetDescription().utf8_str()
			<< std::endl;
		out << "*/"   << std::endl;
		out << "\t"   << pt->GetDeclaration().utf8_str()
			<< std::endl;
		out << std::endl;
		delete pt;
	}
}
