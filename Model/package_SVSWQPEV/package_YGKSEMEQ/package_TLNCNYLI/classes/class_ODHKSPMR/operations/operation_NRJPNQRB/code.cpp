wxTreeItemId aID = myTree->GetRootItem();

wxString repository;

switch (event.GetId())
{
	case ID_SELECTSVN:
		repository = "SVN";
		AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlSVN);
	break;
	default:
		repository = "none";
		AdeRevisionControlBase::SetRevisionControlObject(new AdeRevisionControlNone);
	break;
}

dynamic_cast<AdeModel*>(myTree->GetItem(aID))->SetRepository(repository);