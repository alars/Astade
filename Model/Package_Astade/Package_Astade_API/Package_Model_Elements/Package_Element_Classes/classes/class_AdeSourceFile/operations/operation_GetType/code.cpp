if (myFileName.GetExt() == wxS("cpp"))
	return ITEM_IS_CPPFILE;
if (myFileName.GetExt() == wxS("c"))
	return ITEM_IS_CPPFILE;
if (myFileName.GetExt() == wxS("h"))
	return ITEM_IS_HFILE;
if (myFileName.GetExt() == wxS("dox"))
	return ITEM_IS_DOXFILE;

return ITEM_IS_FILE;
