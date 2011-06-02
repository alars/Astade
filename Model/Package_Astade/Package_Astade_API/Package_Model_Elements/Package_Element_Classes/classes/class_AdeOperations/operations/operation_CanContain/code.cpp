//~~ bool CanContain(AdeModelElement& anElement) [AdeOperations] ~~

bool retVal = false;
switch (anElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_OPERATION:	
		retVal = true;
}

return retVal;
