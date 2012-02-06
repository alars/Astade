//~~ void memberAttribute(std::ofstream& out, bool spec, int visibility) [CGenerator] ~~

std::map<wxString, const AdeAttribute*, AdeStringCompare> attrs;

wxFileName attributes(source->GetFileName());
attributes.AppendDir(wxS("attributes"));

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
				wxString seq = wxString::Format(wxS("%02lx"), pa->GetType() & 0xff) + pa->GetName();
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
		out << "/** " << (const char*)pa->GetDescription().utf8_str() << std::endl;
		if (pa->IsDeprecated())		
			out << "@deprecated " << (const char*)pa->GetDeprecatedDesc().utf8_str() << std::endl;
		out << "*/"   << std::endl;

		out << "\t";
		if (pa->IsConst())
			out << "const ";
		out << (const char*)pa->GetCodingType().utf8_str()
			<< "\t" << (const char*)pa->GetName().utf8_str();

		if (!pa->GetBits().empty())
			out << "\t: " << (const char*)pa->GetBits().utf8_str();

		if (pa->IsDeprecated())
			out << " __attribute__ ((deprecated))";

		out << ";" << std::endl << std::endl;
		AttributeList.push_back(pa->GetName());
	}
}
