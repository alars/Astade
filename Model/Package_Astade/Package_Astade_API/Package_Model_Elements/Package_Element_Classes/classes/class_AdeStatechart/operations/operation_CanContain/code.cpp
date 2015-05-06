//~~ bool CanContain(AdeModelElement& anElement) [AdeStatechart] ~~

bool retVal = false;
switch (anElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_STATE:
		retVal = true;
	case ITEM_IS_TRANSITION:
		retVal = true;
}

return retVal;
