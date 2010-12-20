//~~ bool CanContain(AdeModelElement& aElement) [AdePorts] ~~
bool retVal = false;

switch(aElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_PORT:
		retVal = true;
}

return retVal;