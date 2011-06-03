//~~ AdeModelElement* GetModelElement() [AstadeLoading] ~~

AdeModelElement* anElement = AdeModelElement::CreateNewElement(elementFileName);
AstadeTreeItemBase* aBaseElement = AstadeTreeItemBase::CreateNewElement(anElement);
ourTree->SetItemData(GetId(), aBaseElement);
aBaseElement->SetNeedUpdate();
delete this;

return anElement;
