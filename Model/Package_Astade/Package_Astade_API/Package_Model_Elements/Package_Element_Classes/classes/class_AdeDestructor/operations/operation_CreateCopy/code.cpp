//~~ wxFileName CreateCopy(wxFileName parentPath) [AdeDestructor] ~~

// let the base class do the main work
wxFileName aFileName = AdeDirectoryElement::CreateCopy(parentPath);

wxFileConfig theConfig(wxEmptyString, wxEmptyString, aFileName.GetFullPath());

theConfig.Write(wxS("Astade/Description"), myConfig->Read(wxS("Astade/Description")));
theConfig.Write(wxS("Astade/Virtual"), myConfig->Read(wxS("Astade/Virtual")));

return aFileName;
