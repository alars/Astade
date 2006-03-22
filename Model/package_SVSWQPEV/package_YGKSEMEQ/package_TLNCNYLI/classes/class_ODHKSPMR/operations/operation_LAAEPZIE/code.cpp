wxMenu* aSubUp =  new wxMenu("");

aSubUp->AppendRadioItem(ID_SELECTNONE,"none");
aSubUp->AppendRadioItem(ID_SELECTSVN,"SVN");
aSubUp->AppendRadioItem(ID_SELECTGIT,"git");
aSubUp->AppendRadioItem(ID_SELECTCVS,"CVS");
aSubUp->Enable(ID_SELECTGIT,false);
aSubUp->Enable(ID_SELECTCVS,false);


wxTreeItemId aID = myTree->GetRootItem();

if (dynamic_cast<AdeModel*>(myTree->GetItem(aID))->GetRepository() == "SVN")
	aSubUp->Check(ID_SELECTSVN,true);
else
	aSubUp->Check(ID_SELECTNONE,true);

return aSubUp;
