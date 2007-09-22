wxFileName aFileName = AdeDirectoryElement::CreateNewElement(parentFolder,"operation",ITEM_IS_OPERATION | ITEM_IS_NORMALOP | ITEM_IS_PRIVATE,true);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());

theConfig.Write("Astade/CodingType", codingType);

theConfig.Write("Astade/Name",operationName);

if (isVirtual)
	theConfig.Write("Astade/Virtual", "yes");
else
	theConfig.Write("Astade/Virtual", "no");

if (isAbstract)
	theConfig.Write("Astade/Abstract", "yes");
else
	theConfig.Write("Astade/Abstract", "no");

if (isStatic)
	theConfig.Write("Astade/Static", "yes");
else
	theConfig.Write("Astade/Static", "no");

if (isConst)
	theConfig.Write("Astade/Const", "yes");
else
	theConfig.Write("Astade/Const", "no");

if (isInline)
	theConfig.Write("Astade/Inline", "yes");
else
	theConfig.Write("Astade/Inline", "no");

return aFileName;