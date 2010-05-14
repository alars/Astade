// let the base class do the main work
wxFileName aFileName = AdeDirectoryElement::CreateCopy(parentPath);

wxFileConfig theConfig(wxEmptyString, wxEmptyString, aFileName.GetFullPath());
wxFileConfig copyConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());

theConfig.Write(wxS("Astade/Description"), copyConfig.Read(wxS("Astade/Description")));
theConfig.Write(wxS("Astade/Virtual"), copyConfig.Read(wxS("Astade/Virtual")));

return aFileName;
