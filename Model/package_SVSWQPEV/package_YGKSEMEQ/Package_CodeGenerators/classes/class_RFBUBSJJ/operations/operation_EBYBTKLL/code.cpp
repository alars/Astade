/* vi: set tabstop=4: */

wxFileName parameterPath(op.GetFileName());
parameterPath.AppendDir("parameters");
wxString paramlist;

if (wxDir::Exists(parameterPath.GetPath()))
{
	wxDir dir(parameterPath.GetPath());
	wxString filename;

	bool cont = dir.GetFirst(&filename, "*.ini");
	while (cont)
	{
		wxFileName FullName(parameterPath);
		FullName.SetFullName(filename);
		const AdeModelElement* pe = AdeModelElement::CreateNewElement(FullName);
		if ((pe->GetType() & ITEM_IS_PARAMETER) == ITEM_IS_PARAMETER)
		{
			const AdeParameter* pp = dynamic_cast<const AdeParameter*>(pe);
			assert(pp);
			int number = pp->GetType() & 0xff;
			params[number] = pp;
		}
		else
			delete pe;
		cont = dir.GetNext(&filename);
	}

	std::map<int,const AdeParameter*>::iterator it;
	for (it = params.begin(); it != params.end(); ++it)
	{
		if (!paramlist.empty())
			paramlist += ", ";
		paramlist += (*it).second->GetCodingType()
		          +  " " + (*it).second->GetName();
		if (!keep)
			delete (*it).second;
	}
}
return paramlist;
