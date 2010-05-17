//~~ bool CanContain(AdeModelElement& aElement) [AdeClass] ~~
bool retVal = false;

if(IsLibClass())
{
	// TODO: Is this really a good idea? For now it is okay, but...
	retVal = true;
}
else
{
	switch(aElement.GetType() & ITEM_TYPE_MASK)
	{
		case ITEM_IS_ATTRIBUTES:
		case ITEM_IS_OPERATIONS:
		case ITEM_IS_TYPES:	
			retVal = true;
	}
}

return retVal;