wxFileName aFileName = AdeFileElement::CreateNewElement(parentFolder, "type", ITEM_IS_TYPE, true);

wxFileConfig theConfig(wxEmptyString, wxEmptyString, aFileName.GetFullPath());
theConfig.Write("Astade/Declaration", "//>>> place the declaration here; use '%s' to insert the name <<<");
return aFileName;
