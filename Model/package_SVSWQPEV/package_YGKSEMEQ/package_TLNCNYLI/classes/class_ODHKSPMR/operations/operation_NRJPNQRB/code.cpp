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
	default:
		repository = "none";
		AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlNone);
		break;
}

dynamic_cast<AdeModel*>(myTree->GetItem(aID))->SetRepository(repository);

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
myMenuBar->GetMenu(0)->Enable(ID_RENAME,theRevisionControl->IsRenameSupported());
