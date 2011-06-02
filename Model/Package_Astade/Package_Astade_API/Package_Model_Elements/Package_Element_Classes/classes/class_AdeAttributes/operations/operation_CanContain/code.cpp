//~~ bool CanContain(AdeModelElement& anElement) [AdeAttributes] ~~

bool retVal = false;
switch (anElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_ATTRIBUTE:
		retVal = true;
}

return retVal;
