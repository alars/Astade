wxMenu* aSubUp = new wxMenu(wxEmptyString);

aSubUp->Append(-1, "Targets:", wxEmptyString, wxITEM_NORMAL);
aSubUp->AppendSeparator();

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
			aSubUp->Append(ID_MAKEMIN+i, targets[i], wxEmptyString, wxITEM_NORMAL);
		}
	}
	else
	{
		aSubUp->Append(ID_NOMAKE, "no targets", wxEmptyString, wxITEM_NORMAL);
		aSubUp->Enable(ID_NOMAKE, false);
	}
}
else
{
	aSubUp->Append(ID_NOMAKE, "no Makefile", wxEmptyString, wxITEM_NORMAL);
	aSubUp->Enable(ID_NOMAKE, false);
}

return aSubUp;
