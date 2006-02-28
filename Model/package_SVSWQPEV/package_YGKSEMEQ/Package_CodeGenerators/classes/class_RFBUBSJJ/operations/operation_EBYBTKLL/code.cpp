/* vi: set tabstop=4: */

wxFileName parameterPath(Operationpath);
parameterPath.AppendDir("parameters");
wxString paramlist;

if (wxDir::Exists(parameterPath.GetPath()))
{
	wxDir dir(parameterPath.GetPath());
	wxString filename;

	wxString params[256];
	wxString types [256];

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
			params[number] = pp->GetName();
			types [number] = pp->GetCodingType();
		}
		delete pe;
		cont = dir.GetNext(&filename);
	}

	for (int i = 0; i < 256; ++i)
	{
		if (!params[i].empty())
		{
			if (!paramlist.empty())
				paramlist += ",";
			paramlist += types[i] + " " + params[i];
		}
	}
}
return paramlist;
