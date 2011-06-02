//~~ AdeModelElement* GetItem(wxTreeItemId anID) [AstadeTree] ~~

AstadeTreeItemBase* anAstadeTreeItemBase = dynamic_cast<AstadeTreeItemBase*>(GetItemData(anID));
if (anAstadeTreeItemBase)
	return anAstadeTreeItemBase->GetModelElement();
else
	return 0;
