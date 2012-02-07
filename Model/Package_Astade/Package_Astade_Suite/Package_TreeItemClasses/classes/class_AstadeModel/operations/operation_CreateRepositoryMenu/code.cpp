//~~ wxMenu* CreateRepositoryMenu() [AstadeModel] ~~

wxMenu* aSubUp = new wxMenu(wxEmptyString);

aSubUp->AppendRadioItem(ID_SELECTNONE, wxS("none"));
aSubUp->AppendRadioItem(ID_SELECTSVN, wxS("SVN / git-svn"));
aSubUp->Enable(ID_SELECTSVN, AdeRevisionControlSVN::IsAvailable());
aSubUp->AppendRadioItem(ID_SELECTGIT, wxS("Git"));
aSubUp->Enable(ID_SELECTGIT, AdeRevisionControlGIT::IsAvailable());
aSubUp->AppendRadioItem(ID_SELECTMKS, wxS("MKS"));
aSubUp->Enable(ID_SELECTMKS, AdeRevisionControlMKS::IsAvailable());
aSubUp->AppendRadioItem(ID_SELECTCVS, wxS("CVS"));

AdeModel* theModel = dynamic_cast<AdeModel*>(myModelElement);

if (!theModel->GetRepository().CmpNoCase(wxS("CVS")))
	aSubUp->Check(ID_SELECTCVS, true);
else if (!theModel->GetRepository().CmpNoCase(wxS("SVN")))
	aSubUp->Check(ID_SELECTSVN, true);
else if (!theModel->GetRepository().CmpNoCase(wxS("MKS")))
	aSubUp->Check(ID_SELECTMKS, true);
else if (!theModel->GetRepository().CmpNoCase(wxS("Git")))
	aSubUp->Check(ID_SELECTGIT, true);
else
	aSubUp->Check(ID_SELECTNONE, true);

return aSubUp;
