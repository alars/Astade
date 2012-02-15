//~~ void staticAttribute(std::ofstream& out, bool spec, int visibility) [CppGenerator] ~~

std::set<const AdeAttribute*, AdeElementCompare> attrs;

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
				attrs.insert(pa);
			else
				delete pa;
		}
		else
			delete pe;
		cont = dir.GetNext(&filename);
	}
}

std::set<const AdeAttribute*>::iterator it;

for (it = attrs.begin(); it != attrs.end(); ++it)
{
	const AdeAttribute* pa = *it;
	if (spec)
	{
		out << "/** "
			<< pa->GetDescription()
			<< std::endl;
		if (pa->IsDeprecated())
			out << "@deprecated "
				<< pa->GetDeprecatedDesc()
				<< std::endl;
		out << "*/"
			<< std::endl;

		out << "\tstatic ";
		if (pa->IsConst())
			out << "const ";
		out << pa->GetCodingType()
			<< "\t"
			<< pa->GetName();

		if (pa->IsDeprecated())
			out << " __attribute__ ((deprecated))";

		out << ";"
			<< std::endl;
	}
	else
	{
		if (pa->IsConst())
			out << "const ";
		out << pa->GetCodingType()
			<< "\t"
			<< getNamespace(source->getNamespace())
			<< source->GetName()
			<< "::"
			<< pa->GetName();
		wxString Default(pa->GetDefault());
		if (!Default.empty())
			out << " = "
				<< Default;
		out << ";"
			<< std::endl;
	}
	out << std::endl;
	delete pa;
}
