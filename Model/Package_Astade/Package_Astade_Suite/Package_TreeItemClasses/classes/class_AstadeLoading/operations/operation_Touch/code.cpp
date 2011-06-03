//~~ void Touch() [AstadeLoading] ~~

AdeModelElement* anElement = AdeModelElement::CreateNewElement(elementFileName);
AstadeTreeItemBase* aBaseElement = AstadeTreeItemBase::CreateNewElement(anElement);
ourTree->SetItemData(GetId(), aBaseElement);
aBaseElement->Touch();
delete this;
