/* vi: set tabstop=4: */

std::map<wxString,wxString> attributenames;

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
	            wxString theName(pa->GetName());
				attributenames[theName] = pa->GetCodingType();
        	    wxString Default(pa->GetDefault());
				if (!Default.empty())
					memberDefaults[theName] = Decode(Default);
			}
		}
		delete pe;
		cont = dir.GetNext(&filename);
	}
}

std::map<wxString,wxString>::iterator it;

for (it = attributenames.begin(); it != attributenames.end(); ++it)
{
	if (spec)
	{
		out << "\t" << (*it).second.c_str()
			<< "\t" << (*it).first.c_str() << ";" << std::endl;
		AttributeList.push_back((*it).first);
	}
}
