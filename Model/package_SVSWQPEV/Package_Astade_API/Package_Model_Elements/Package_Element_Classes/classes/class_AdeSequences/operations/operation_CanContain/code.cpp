bool retVal = false;

switch(aElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_SEQUENCE:	
		retVal = true;
}

return retVal;