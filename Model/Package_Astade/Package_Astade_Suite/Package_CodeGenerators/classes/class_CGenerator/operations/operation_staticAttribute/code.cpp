//~~ void staticAttribute(std::ofstream& out, bool spec, int visibility) [CGenerator] ~~

std::list<const AdeAttribute*> attrs;

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
            if (pa->IsStatic())
				attrs.push_back(pa);
			else
				delete pa;
		}
		else
			delete pe;
		cont = dir.GetNext(&filename);
	}
}

std::list<const AdeAttribute*>::iterator it;

for (it = attrs.begin(); it != attrs.end(); ++it)
{
	if (spec)
	{
		out << "/** " << (const char*)(*it)->GetDescription().utf8_str() << std::endl;
		if ((*it)->IsDeprecated())
			out << "@deprecated " << (const char*)(*it)->GetDeprecatedDesc().utf8_str() << std::endl;
		out << "*/"   << std::endl;

		out << "extern ";
		if ((*it)->IsConst())
			out << "const ";
		out << (const char*)(*it)->GetCodingType().utf8_str()
			<< "\t" << (const char*)source->GetName().utf8_str()
            << "_"  << (const char*)(*it)->GetName().utf8_str();

		if ((*it)->IsDeprecated())
			out << " __attribute__ ((deprecated))";

		out << ";" << std::endl;
	}
	else
	{
		if ((*it)->IsConst())
			out << "const ";
		out << (const char*)(*it)->GetCodingType().utf8_str()
			<< "\t"  << (const char*)source->GetName().utf8_str()
			<< "_"  << (const char*)(*it)->GetName().utf8_str();
		wxString Default((*it)->GetDefault());
		if (!Default.empty())
			out << " = " << (const char*)Default.utf8_str();
		out << ";" << std::endl;
	}
	out << std::endl;
}
