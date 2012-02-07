//~~ void AppendMakeTargets(wxMenu& aPopUp, bool enabled = true) [AstadeConfiguration] ~~

wxFileName aFileName = myModelElement->GetFileName();
aFileName.SetFullName(wxS("Makefile"));

if(aFileName.FileExists())
{
	AstadeMake myAstadeMake(new AdeMake(aFileName));

	wxArrayString targets(myAstadeMake.GetMakeTargets());

	if (targets.Count())
	{
		for (size_t i = 0; i < targets.Count() && i < (ID_MAKEMAX - ID_MAKEMIN); ++i)
		{
			aPopUp.Append(ID_MAKEMIN + i, targets[i], wxEmptyString, wxITEM_NORMAL);
			aPopUp.Enable(ID_MAKEMIN + i, enabled);
		}
	}
	else
	{
		aPopUp.Append(ID_NOMAKE, wxS("no targets"), wxEmptyString, wxITEM_NORMAL);
		aPopUp.Enable(ID_NOMAKE, false);
	}
}
else
{
	aPopUp.Append(ID_NOMAKE, wxS("no Makefile"), wxEmptyString, wxITEM_NORMAL);
	aPopUp.Enable(ID_NOMAKE, false);
}
