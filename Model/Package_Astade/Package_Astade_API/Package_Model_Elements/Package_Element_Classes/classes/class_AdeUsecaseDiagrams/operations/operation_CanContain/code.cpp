//~~ bool CanContain(AdeModelElement& anElement) [AdeUsecaseDiagrams] ~~

bool retVal = false;
switch (anElement.GetType() & ITEM_TYPE_MASK)
{
	case ITEM_IS_USECASE:
		retVal = true;
}

return retVal;
