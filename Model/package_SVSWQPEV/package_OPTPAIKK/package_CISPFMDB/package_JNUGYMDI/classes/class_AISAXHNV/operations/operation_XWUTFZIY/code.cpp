wxFileName aFileName = AdeFileElement::CreateNewElement(parentFolder,"event",ITEM_IS_EVENT,true);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());
theConfig.Write("Astade/Declaration", "//place your declaration here");