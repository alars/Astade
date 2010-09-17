//~~ wxArrayString getNamespace() [AdeClass] ~~

wxArrayString ret;
AdeModelElement* anElement = GetGrandParent();

while (anElement && ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_PACKAGE))
{
    AdePackage* aPackage = dynamic_cast<AdePackage*>(anElement);
    if (aPackage->isNamespace())
        ret.Insert(aPackage->GetLabel(), 0);
    AdeModelElement* helper = anElement;
    anElement = anElement->GetParent();
    delete helper;
}

delete anElement;

return ret;
