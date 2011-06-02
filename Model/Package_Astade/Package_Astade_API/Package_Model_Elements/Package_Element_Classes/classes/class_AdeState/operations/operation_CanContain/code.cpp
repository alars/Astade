//~~ bool CanContain(AdeModelElement& anElement) [AdeState] ~~

bool retVal = false;
switch (anElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_TRANSITION:
		retVal = true;
}

return retVal;
