wxFileName aFileName = AdeFileElement::CreateNewElement(parentFolder,"transition",ITEM_IS_TRANSITION,true);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());

theConfig.Write("Astade/TransitionType", "Normal");

return aFileName;