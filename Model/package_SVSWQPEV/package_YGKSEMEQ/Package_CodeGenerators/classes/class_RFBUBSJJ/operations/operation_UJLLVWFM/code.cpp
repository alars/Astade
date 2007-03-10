/* vi: set tabstop=4: */

std::list<const AdeAttribute*> attrs;

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
				attrs.push_back(pa);
			}
			else
				delete pa;
		} else
			delete pe;
		cont = dir.GetNext(&filename);
	}
}

std::list<const AdeAttribute*>::iterator it;

for (it = attrs.begin(); it != attrs.end(); ++it)
{
	if (spec)
	{
		out << "/** " << (*it)->GetDescription() << std::endl;
		out << "*/"   << std::endl;

		out << "\t";
		if ((*it)->IsConst())
			out << "const ";
		out << (*it)->GetCodingType()
			<< "\t" << (*it)->GetName()
			<< ";" << std::endl;
		out << std::endl;
		AttributeList.push_back((*it)->GetName());
	}
}
