//~~ void ShowHtml(wxCommandEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = myTree->GetSelection();
wxLaunchDefaultBrowser(wxString("file://") + myTree->GetItem(anID)->GetFileName().GetFullPath());
