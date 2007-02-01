bool retVal = false;

switch(aElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_ATTRIBUTES:
	case ITEM_IS_OPERATIONS:
	case ITEM_IS_TYPES:	
		retVal = true;
}

return retVal;