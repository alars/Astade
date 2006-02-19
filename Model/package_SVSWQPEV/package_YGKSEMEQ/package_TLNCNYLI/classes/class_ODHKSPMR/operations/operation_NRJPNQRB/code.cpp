wxTreeItemId aID = myTree->GetRootItem();

wxString repository = "none";
switch (event.GetId())
{
	case ID_SELECTSVN:  repository = "SVN"; break;
}

static_cast<AdeModel*>(myTree->GetItem(aID))->SetRepository(repository);