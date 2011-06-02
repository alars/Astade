//~~ bool CanContain(AdeModelElement& anElement) [AdeClasses] ~~

bool retVal = false;
switch (anElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_CLASS:
	case ITEM_IS_STATECHART:
		retVal = true;
}

return retVal;
