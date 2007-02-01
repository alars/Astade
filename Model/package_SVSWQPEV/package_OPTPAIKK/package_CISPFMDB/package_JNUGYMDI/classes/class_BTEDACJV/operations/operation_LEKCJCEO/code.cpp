bool retVal = false;

switch(aElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_MAKE:
		retVal = true;
}

return retVal;