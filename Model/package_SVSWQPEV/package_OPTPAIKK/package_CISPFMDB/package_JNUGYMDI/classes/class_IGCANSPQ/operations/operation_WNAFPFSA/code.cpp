wxFileName aFileName = AdeDirectoryElement::CreateNewElement(parentFolder,"operation",ITEM_IS_OPERATION | ITEM_IS_NORMALOP | ITEM_IS_PRIVATE,true);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());

theConfig.Write("Astade/CodingType", "void");
theConfig.Write("Astade/Virtual", "no");
theConfig.Write("Astade/Abstract", "no");
theConfig.Write("Astade/Static", "no");
theConfig.Write("Astade/Const", "no");
