bool retVal = false;

switch(aElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_TYPE:	
		retVal = true;
}

return retVal;