// let the base class do the main work
wxFileName aFileName = AdeDirectoryElement::CreateCopy(parentPath);

wxFileConfig theConfig(wxEmptyString, wxEmptyString, aFileName.GetFullPath());
wxFileConfig copyConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());

theConfig.Write("Astade/Description", copyConfig.Read("Astade/Description"));
theConfig.Write("Astade/Virtual", copyConfig.Read("Astade/Virtual"));

return aFileName;
