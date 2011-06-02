//~~ AstadeTreeItemBase* GetItemObject(wxTreeItemId anID) [AstadeTree] ~~

return dynamic_cast<AstadeTreeItemBase*>(GetItemData(anID));
