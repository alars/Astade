AstadeTreeItemBase* aAstadeTreeItemBase = dynamic_cast<AstadeTreeItemBase*>(GetItemData(aID));
if (aAstadeTreeItemBase)
	return aAstadeTreeItemBase->GetModelElement();
else
	return 0;