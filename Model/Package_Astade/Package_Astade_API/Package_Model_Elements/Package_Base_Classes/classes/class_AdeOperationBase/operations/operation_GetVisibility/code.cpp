int	theType = GetType();

if (theType & ITEM_IS_PRIVATE)
	return wxS("private");

if (theType & ITEM_IS_PROTECTED)
	return wxS("protected");

return wxS("public");
