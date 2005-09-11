#define ITEM_IS_PROTECTED   0x000400
#define ITEM_IS_PRIVATE     0x000800

wxFileConfig theConfig(wxEmptyString,wxEmptyString,wxEmptyString,myFileName.GetFullPath());

int	theType;
theConfig.Read("Astade/Type",&theType);

if (theType & ITEM_IS_PRIVATE)
	return 24;

if (theType & ITEM_IS_PROTECTED)
	return 25;

return 23;