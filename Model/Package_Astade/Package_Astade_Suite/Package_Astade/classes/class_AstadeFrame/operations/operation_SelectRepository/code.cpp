//~~ void SelectRepository(wxCommandEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = myTree->GetRootItem();

wxString repository;

switch (event.GetId())
{
case ID_SELECTCVS:
	repository = wxS("CVS");
	AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlCVS);
	break;

case ID_SELECTSVN:
	repository = wxS("SVN");
	if (!wxFileName::DirExists(wxS(".svn")))
		AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlGIT);
	else
		AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlSVN);
	break;

case ID_SELECTGIT:
	repository = wxS("git");
	AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlGIT);
	break;

case ID_SELECTMKS:
{
	AdeModel* model = dynamic_cast<AdeModel*>(myTree->GetItem(anID));
	wxString projectFile = wxGetTextFromUser(wxS("Give the Filename of the MKS project file for this model."), wxS("project filename"), model->GetRepositoryProjectFile());
	repository = wxS("MKS");
	AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlMKS(projectFile));
	model->SetRepositoryProjectFile(projectFile);
	break;
}

default:
	repository = wxS("none");
	AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlNone);
	break;
}

dynamic_cast<AdeModel*>(myTree->GetItem(anID))->SetRepository(repository);
