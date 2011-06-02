//~~ bool CanContain(AdeModelElement& anElement) [AdeRelations] ~~

bool retVal = false;
switch (anElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_RELATION:
	case ITEM_IS_INRELATION:
		retVal = true;
}

return retVal;
