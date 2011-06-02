//~~ bool CanContain(AdeModelElement& anElement) [AdeClass] ~~

bool retVal = false;
if (IsLibClass())
{
	// TODO: Is this really a good idea? For now it is okay, but...
	retVal = true;
}
else
{
	switch (anElement.GetType() & ITEM_TYPE_MASK)
	{
		case ITEM_IS_ATTRIBUTES:
		case ITEM_IS_OPERATIONS:
		case ITEM_IS_TYPES:	
			retVal = true;
	}
}

return retVal;
