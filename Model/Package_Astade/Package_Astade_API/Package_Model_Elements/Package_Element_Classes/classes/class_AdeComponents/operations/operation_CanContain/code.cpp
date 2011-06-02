//~~ bool CanContain(AdeModelElement& anElement) [AdeComponents] ~~

bool retVal = false;
switch (anElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_COMPONENT:	
		retVal = true;
}

return retVal;
