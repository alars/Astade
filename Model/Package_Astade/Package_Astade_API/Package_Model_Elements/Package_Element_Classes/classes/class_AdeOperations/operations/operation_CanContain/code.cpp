bool retVal = false;

switch(aElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_OPERATION:	
		retVal = true;
}

return retVal;