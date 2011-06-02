//~~ void OmdDialog(wxCommandEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = myTree->GetSelection();
myOmdDialog->DlgShow(myTree->GetItem(anID)->GetFileName());
