//~~ wxMenu* CreateRepositoryMenu() [AstadeModel] ~~
wxMenu* aSubUp = new wxMenu(wxEmptyString);

aSubUp->AppendRadioItem(ID_SELECTNONE, "none");
aSubUp->AppendRadioItem(ID_SELECTSVN, "SVN / git-svn");
aSubUp->Enable(ID_SELECTSVN, AdeRevisionControlSVN::IsAvailable());
aSubUp->AppendRadioItem(ID_SELECTGIT, "Git");
aSubUp->Enable(ID_SELECTGIT, AdeRevisionControlGIT::IsAvailable());
aSubUp->AppendRadioItem(ID_SELECTMKS, "MKS");
aSubUp->Enable(ID_SELECTMKS, AdeRevisionControlMKS::IsAvailable());
aSubUp->AppendRadioItem(ID_SELECTCVS, "CVS");

AdeModel* theModel = dynamic_cast<AdeModel*>(myModelElement);

if (!theModel->GetRepository().CmpNoCase("CVS"))
	aSubUp->Check(ID_SELECTCVS, true);
else if (!theModel->GetRepository().CmpNoCase("SVN"))
	aSubUp->Check(ID_SELECTSVN, true);
else if (!theModel->GetRepository().CmpNoCase("MKS"))
	aSubUp->Check(ID_SELECTMKS, true);
else if (!theModel->GetRepository().CmpNoCase("Git"))
	aSubUp->Check(ID_SELECTGIT, true);
else
	aSubUp->Check(ID_SELECTNONE, true);

return aSubUp;
