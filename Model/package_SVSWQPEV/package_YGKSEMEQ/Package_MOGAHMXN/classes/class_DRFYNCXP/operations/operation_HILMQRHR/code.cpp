wxFileName aFileName = myModelElement->GetFileName();
aFileName.SetFullName("Makefile");

if(aFileName.FileExists())
{
	AstadeMake myAstadeMake(new AdeMake(aFileName));

	wxArrayString targets(myAstadeMake.GetMakeTargets());

	if(targets.Count())
	{
		for(size_t i=0; (i<targets.Count()) && i<(ID_MAKEMAX-ID_MAKEMIN); i++)
		{
			aPopUp.Append(ID_MAKEMIN+i, targets[i], wxEmptyString, wxITEM_NORMAL);
		}
	}
	else
	{
		aPopUp.Append(ID_NOMAKE, "no targets", wxEmptyString, wxITEM_NORMAL);
		aPopUp.Enable(ID_NOMAKE, false);
	}
}
else
{
	aPopUp.Append(ID_NOMAKE, "no Makefile", wxEmptyString, wxITEM_NORMAL);
	aPopUp.Enable(ID_NOMAKE, false);
}


