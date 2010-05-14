wxFileName aFileName = AdeFileElement::CreateNewElement(parentFolder, wxS("type"), ITEM_IS_TYPE, true);

wxFileConfig theConfig(wxEmptyString, wxEmptyString, aFileName.GetFullPath());
theConfig.Write(wxS("Astade/Declaration"), wxS("//>>> place the declaration here; use '%s' to insert the name <<<"));
return aFileName;
