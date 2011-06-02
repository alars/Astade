//~~ bool CanContain(AdeModelElement& anElement) [AdeParameters] ~~

bool retVal = false;
switch (anElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_PARAMETER:
		retVal = true;
}

return retVal;
