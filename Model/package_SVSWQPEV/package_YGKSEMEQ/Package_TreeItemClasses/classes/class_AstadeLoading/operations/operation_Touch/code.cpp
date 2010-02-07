AdeModelElement* aElement = AdeModelElement::CreateNewElement(elementFileName);
AstadeTreeItemBase* aBaseElement = AstadeTreeItemBase::CreateNewElement(aElement);
ourTree->SetItemData(GetId(),aBaseElement);
aBaseElement->Touch();
delete this;