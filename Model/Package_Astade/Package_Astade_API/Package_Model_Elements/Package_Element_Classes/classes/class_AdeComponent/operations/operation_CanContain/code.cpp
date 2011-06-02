//~~ bool CanContain(AdeModelElement& anElement) [AdeComponent] ~~

bool retVal = false;
switch (anElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_CONFIGURATION:
	case ITEM_IS_USECASEDIAGRAMS:
		retVal = true;
}

return retVal;
