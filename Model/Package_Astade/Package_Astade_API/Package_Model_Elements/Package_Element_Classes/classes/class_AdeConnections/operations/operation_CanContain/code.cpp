//~~ bool CanContain(AdeModelElement& aElement) [AdeConnections] ~~
bool retVal = false;

switch(aElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_CONNECTION:
		retVal = true;
}

return retVal;