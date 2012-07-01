//~~ std::list<AdePackage*> getNamespacePackages() [AdeClass] ~~

std::list<AdePackage*> list;
AdeModelElement* anElement = GetGrandParent();

while (anElement && ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_PACKAGE))
{
	AdePackage* aPackage = dynamic_cast<AdePackage*>(anElement);
	AdeModelElement* helper = anElement;
	anElement = anElement->GetParent();
	if (aPackage->isNamespace())
		list.push_back(aPackage);
	else
		delete helper;
}

delete anElement;

return list;
