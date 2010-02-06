bool retVal = false;

switch(aElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_RELATION:
	case ITEM_IS_INRELATION:
		retVal = true;
}

return retVal;