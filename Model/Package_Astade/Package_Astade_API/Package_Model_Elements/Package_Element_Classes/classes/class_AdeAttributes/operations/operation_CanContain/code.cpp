//~~ bool CanContain(AdeModelElement& aElement) [AdeAttributes] ~~
bool retVal = false;

switch(aElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_ATTRIBUTE:
		retVal = true;
}

return retVal;