int	theType = GetType();

if (theType & ITEM_IS_PRIVATE)
	return "private";

if (theType & ITEM_IS_PROTECTED)
	return "protected";

return "public";