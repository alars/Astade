bool retVal = false;

switch(aElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_COMPONENTS:
	case ITEM_IS_PACKAGE:
		retVal = true;
}

return retVal;