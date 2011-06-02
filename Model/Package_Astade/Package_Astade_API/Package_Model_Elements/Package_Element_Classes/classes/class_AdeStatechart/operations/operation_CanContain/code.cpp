//~~ bool CanContain(AdeModelElement& anElement) [AdeStatechart] ~~

bool retVal = false;
switch (anElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_STATE:
		retVal = true;
}

return retVal;
