wxMenu* aSubUp = new wxMenu(wxEmptyString);

aSubUp->AppendRadioItem(ID_SELECTNONE, "none");
aSubUp->AppendRadioItem(ID_SELECTSVN, "SVN");
aSubUp->AppendRadioItem(ID_SELECTGIT, "git");
aSubUp->AppendRadioItem(ID_SELECTCVS, "CVS");
aSubUp->Enable(ID_SELECTCVS, false);

wxTreeItemId aID = myTree->GetRootItem();
AdeModel* theModel = dynamic_cast<AdeModel*>(myTree->GetItem(aID));

if (theModel->GetRepository() == "SVN")
	aSubUp->Check(ID_SELECTSVN, true);
else if (theModel->GetRepository() == "git")
	aSubUp->Check(ID_SELECTGIT, true);
else
	aSubUp->Check(ID_SELECTNONE, true);

return aSubUp;
