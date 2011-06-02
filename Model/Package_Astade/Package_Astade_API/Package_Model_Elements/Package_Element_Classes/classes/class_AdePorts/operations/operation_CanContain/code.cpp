//~~ bool CanContain(AdeModelElement& anElement) [AdePorts] ~~

bool retVal = false;
switch (anElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_PORT:
		retVal = true;
}

return retVal;
