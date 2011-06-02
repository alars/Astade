//~~ bool CanContain(AdeModelElement& anElement) [AdeSequences] ~~

bool retVal = false;
switch (anElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_SEQUENCE:	
		retVal = true;
}

return retVal;
