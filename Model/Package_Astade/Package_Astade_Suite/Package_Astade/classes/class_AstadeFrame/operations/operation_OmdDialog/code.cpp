wxTreeItemId aID = myTree->GetSelection();
myOmdDialog->DlgShow(myTree->GetItem(aID)->GetFileName());
