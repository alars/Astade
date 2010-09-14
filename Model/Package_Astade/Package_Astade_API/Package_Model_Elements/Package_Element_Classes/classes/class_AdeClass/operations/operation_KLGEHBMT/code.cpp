//~~ std::list<wxString> getNamespace() [AdeClass] ~~
std::list<wxString> ret;
AdeModelElement* anElement = GetGrandParent();

while (anElement && ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_PACKAGE))
{
    AdePackage* aPackage = dynamic_cast<AdePackage*>(anElement);
    if (aPackage->isNamespace())
        ret.push_front(aPackage->GetLabel());
    AdeModelElement* helper = anElement;
    anElement = anElement->GetParent();
    delete helper;
}

delete anElement;

return ret;
