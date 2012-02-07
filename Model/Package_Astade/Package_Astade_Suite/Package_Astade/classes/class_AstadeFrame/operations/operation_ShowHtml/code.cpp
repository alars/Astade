//~~ void ShowHtml(wxCommandEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = myTree->GetSelection();
wxLaunchDefaultBrowser(wxS("file://") + myTree->GetItem(anID)->GetFileName().GetFullPath());
