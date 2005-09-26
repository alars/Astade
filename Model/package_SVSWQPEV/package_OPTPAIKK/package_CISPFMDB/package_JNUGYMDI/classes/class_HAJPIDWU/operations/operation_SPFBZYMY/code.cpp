wxFileName aFileName = AdeFileElement::CreateNewElement(parentFolder,"attribute",ITEM_IS_ATTRIBUTE | ITEM_IS_PRIVATE,true);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());

theConfig.Write("Astade/CodingType", "int");
theConfig.Write("Astade/Static", "no");
theConfig.Write("Astade/Const", "no");
