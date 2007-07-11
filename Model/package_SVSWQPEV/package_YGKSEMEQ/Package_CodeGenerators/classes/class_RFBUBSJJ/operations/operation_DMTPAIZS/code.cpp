/* vi: set tabstop=4: */

wxFileName attributes(source->GetFileName());
attributes.AppendDir("types");

if (wxDir::Exists(attributes.GetPath()))
{
	wxDir dir(attributes.GetPath());
	wxString filename;

	bool cont = dir.GetFirst(&filename, "*.ini");
	while (cont)
	{
		wxFileName FullName(attributes);
		FullName.SetFullName(filename);
		const AdeModelElement* pe = AdeModelElement::CreateNewElement(FullName);
		if ((pe->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TYPE)
		{
			const AdeType* pt = dynamic_cast<const AdeType*>(pe);
			assert(pt);
			out << "/** " << (const char*)pt->GetDescription() << std::endl;
			out << "*/"   << std::endl;
			out << "\t"   << (const char*)pt->GetDeclaration() << std::endl;
			out << std::endl;
		}
		delete pe;
		cont = dir.GetNext(&filename);
	}
}
