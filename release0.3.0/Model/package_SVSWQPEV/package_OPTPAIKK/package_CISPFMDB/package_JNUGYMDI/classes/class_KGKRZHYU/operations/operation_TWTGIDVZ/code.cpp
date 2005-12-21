#define ITEM_IS_HFILE           0x1400000
#define ITEM_IS_CPPFILE         0x1500000
#define ITEM_IS_FILE            0x1600000


if (myFileName.GetExt()=="cpp")
	return ITEM_IS_CPPFILE;
if (myFileName.GetExt()=="h")
	return ITEM_IS_HFILE;

return ITEM_IS_FILE;