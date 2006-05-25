wxFileName aFileName = AdeFileElement::CreateNewElement(parentFolder,"type",ITEM_IS_TYPE,true);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());
theConfig.Write("Astade/Declaration", "//place your declaration here");
return aFileName;