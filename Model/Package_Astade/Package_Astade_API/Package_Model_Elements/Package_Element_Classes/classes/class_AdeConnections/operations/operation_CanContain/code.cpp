//~~ bool CanContain(AdeModelElement& anElement) [AdeConnections] ~~

bool retVal = false;
switch (anElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_CONNECTION:
		retVal = true;
}

return retVal;
