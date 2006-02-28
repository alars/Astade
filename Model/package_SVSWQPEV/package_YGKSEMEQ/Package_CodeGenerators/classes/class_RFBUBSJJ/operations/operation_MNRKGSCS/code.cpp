/* vi: set tabstop=4: */

std::map<wxString,wxString> attributenames;
std::map<wxString,wxString> attributedefaults;

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
            if (pa->IsStatic())
			{
	            wxString theName(pa->GetName());
				attributenames[theName] = pa->GetCodingType();
        	    wxString Default(pa->GetDefault());
				if (!Default.empty())
					attributedefaults[theName] = Default;
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
		out << "\tstatic " << (*it).second
			<< "\t" << (*it).first
			<< ";"  << std::endl;
	}
	else
	{
		if (attributedefaults.find((*it).first) != attributedefaults.end())
		{
			out << (*it).second
				<< " "   << source->GetName()
				<< "::"  << (*it).first
				<< " = " << attributedefaults[(*it).first]
				<< ";"  << std::endl;
		}
		else
		{
			out << (*it).second
				<< " "  << source->GetName()
				<< "::" << (*it).first
				<< ";"  << std::endl;
		}
	}
}
