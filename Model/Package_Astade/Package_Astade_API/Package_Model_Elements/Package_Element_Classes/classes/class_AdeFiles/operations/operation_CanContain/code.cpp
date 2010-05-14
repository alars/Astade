bool retVal = false;

// the manual-folder may contain any type of (source)file
if (GetLabel() == wxS("manual"))
{
	switch (anElement.GetType() & ITEM_TYPE_MASK)
	{
	case ITEM_IS_MAKE:
	case ITEM_IS_FILE:
	case ITEM_IS_HFILE:
	case ITEM_IS_CPPFILE:
	case ITEM_IS_DOXFILE:
		retVal = true;
	}
}

return retVal;
