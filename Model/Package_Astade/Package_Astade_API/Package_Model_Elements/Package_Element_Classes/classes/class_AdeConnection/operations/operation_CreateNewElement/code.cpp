//~~ wxFileName CreateNewElement(wxFileName parentFolder) [AdeConnection] ~~
wxFileName aFileName = AdeFileElement::CreateNewElement(parentFolder, wxS("connection"), ITEM_IS_CONNECTION, true);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());

return aFileName;
