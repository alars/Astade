//~~ void memberAttribute(std::ofstream& out, bool spec, int visibility) [CppGenerator] ~~

std::map<wxString, const AdeAttribute*, AdeStringCompare> attrs;

wxFileName attributes(source->GetFileName());
attributes.AppendDir("attributes");

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
		if ((pe->GetType() & ITEM_TYPE_MASK) == ITEM_IS_ATTRIBUTE &&
			(pe->GetType() & visibility) == visibility)
		{
			const AdeAttribute* pa = dynamic_cast<const AdeAttribute*>(pe);
			assert(pa);
			if (!pa->IsStatic())
			{
				wxString Default(pa->GetDefault());
				if (!Default.empty())
					memberDefaults[pa->GetName()] = Default;

				wxString seq = wxString::Format("%02lx", pa->GetType() & 0xff) + pa->GetName();
				attrs[seq] = pa;
			}
			else
				delete pa;
		} else
			delete pe;
		cont = dir.GetNext(&filename);
	}
}

std::map<wxString, const AdeAttribute*>::iterator it;

for (it = attrs.begin(); it != attrs.end(); ++it)
{
	const AdeAttribute* pa = it->second;
	if (spec)
	{
		out << "/** " << (const char*)pa->GetDescription().c_str() << std::endl;
		if (pa->IsDeprecated())		
			out << "@deprecated " << (const char*)pa->GetDeprecatedDesc().c_str() << std::endl;
		out << "*/"   << std::endl;

		out << "\t";
		if (pa->IsConst())
			out << "const ";
		out << (const char*)pa->GetCodingType().c_str()
			<< "\t" << (const char*)pa->GetName().c_str();

		if (!pa->GetBits().empty())
			out << "\t: " << (const char*)pa->GetBits().c_str();

		if (pa->IsDeprecated())
			out << " __attribute__ ((deprecated))";

		out << ";" << std::endl << std::endl;
		AttributeList.push_back(pa->GetName());
	}
	delete pa;
}
