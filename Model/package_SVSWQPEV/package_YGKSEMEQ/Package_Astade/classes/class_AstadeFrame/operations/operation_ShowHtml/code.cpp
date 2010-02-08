wxTreeItemId aID = myTree->GetSelection();
wxLaunchDefaultBrowser(wxString("file://")+myTree->GetItem(aID)->GetFileName().GetFullPath());
