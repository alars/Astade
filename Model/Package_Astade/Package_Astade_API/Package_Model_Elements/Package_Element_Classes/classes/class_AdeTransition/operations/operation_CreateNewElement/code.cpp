wxFileName aFileName = AdeFileElement::CreateNewElement(parentFolder, wxS("transition"), ITEM_IS_TRANSITION, true);

wxFileConfig theConfig(wxEmptyString, wxEmptyString, aFileName.GetFullPath());

theConfig.Write(wxS("Astade/TransitionType"), wxS("Normal"));

return aFileName;
