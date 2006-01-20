if (myFileName.GetExt()=="cpp")
	return ITEM_IS_CPPFILE;
if (myFileName.GetExt()=="h")
	return ITEM_IS_HFILE;

return ITEM_IS_FILE;