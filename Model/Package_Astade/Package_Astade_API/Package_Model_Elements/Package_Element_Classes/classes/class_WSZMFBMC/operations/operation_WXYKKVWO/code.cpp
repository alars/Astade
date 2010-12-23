//~~ wxFileName CreateNewElement(wxFileName parentFolder) [AdePort] ~~
wxFileName aFileName = AdeFileElement::CreateNewElement(parentFolder, wxS("port"), ITEM_IS_PORT, true);

wxFileConfig theConfig(wxEmptyString,wxEmptyString,aFileName.GetFullPath());

theConfig.Write(wxS("Astade/directrion"), wxS("out"));
theConfig.Write(wxS("Astade/delegate"), wxS("no"));

return aFileName;
