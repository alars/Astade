//~~ bool CanContain(AdeModelElement& anElement) [AdeTypes] ~~

bool retVal = false;
switch (anElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_TYPE:	
		retVal = true;
}

return retVal;
