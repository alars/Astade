//~~ bool CanContain(AdeModelElement& anElement) [AdePackage] ~~

bool retVal = false;
switch (anElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_PACKAGE:
	case ITEM_IS_CLASSES:
	case ITEM_IS_SEQUENCES:
		retVal = true;
}

return retVal;
