wxTreeItemId aID = myTree->GetRootItem();

wxString repository;

switch (event.GetId())
{
	case ID_SELECTSVN:
		repository = "SVN";
		AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlSVN);
		break;
	case ID_SELECTGIT:
		repository = "git";
		AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlGIT);
		break;
	case ID_SELECTMKS:
	{
		AdeModel* model = dynamic_cast<AdeModel*>(myTree->GetItem(aID));
		wxString projectFile = wxGetTextFromUser("Give the Filename of the MKS project file for this model.","project filename",model->GetRepositoryProjectFile());
		repository = "MKS";
		AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlMKS(projectFile));
		model->SetRepositoryProjectFile(projectFile);
		break;
	}
	default:
		repository = "none";
		AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlNone);
		break;
}

dynamic_cast<AdeModel*>(myTree->GetItem(aID))->SetRepository(repository);
