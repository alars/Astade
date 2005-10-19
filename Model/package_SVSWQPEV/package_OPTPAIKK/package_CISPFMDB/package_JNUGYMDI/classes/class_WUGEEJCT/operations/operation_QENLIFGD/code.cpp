wxFileName aFileName = AdeDirectoryElement::CreateNewElement(parentFolder,"destructor",ITEM_IS_OPERATION | ITEM_IS_DEST  | ITEM_IS_PUBLIC,false);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());

theConfig.Write("Astade/Virtual", "yes");

return aFileName;