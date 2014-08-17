//~~ bool isIf() [AdeState] ~~
for (AdeElementIterator it = begin(); it != end(); ++it)
{
    AdeModelElement* anElement = it.CreateNewElement();
    
    if ((anElement->GetType() & ITEM_TYPE_MASK) == ITEM_IS_TRANSITION)
    {
        AdeTransition* aTransition = dynamic_cast<AdeTransition*>(anElement);
        if (aTransition->IsNormalTransition() &&
            !aTransition->GetDestination().empty() &&
            aTransition->GetGuard().empty() &&
            aTransition->GetTrigger().empty())
                return true;
        else if (aTransition->IsTerminateTransition() &&
            aTransition->GetGuard().empty() &&
            aTransition->GetTrigger().empty())
                return true;
    }
    delete anElement;
}

return false;
