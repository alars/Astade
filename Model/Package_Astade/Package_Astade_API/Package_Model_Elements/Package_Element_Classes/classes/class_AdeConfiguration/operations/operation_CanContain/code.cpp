//~~ bool CanContain(AdeModelElement& anElement) [AdeConfiguration] ~~

bool retVal = false;
switch (anElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_MAKE:
		retVal = true;
}

return retVal;
