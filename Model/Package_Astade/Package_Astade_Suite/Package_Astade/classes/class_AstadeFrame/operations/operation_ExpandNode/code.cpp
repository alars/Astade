//~~ void ExpandNode(wxTreeEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = event.GetItem();
myTree->LoadSubnodes(anID);
