wxFileName aFileName = AdeDirectoryElement::CreateCopy(parentPath); // let the base class do the main work

wxFileConfig theConfig(wxEmptyString, wxEmptyString, aFileName.GetFullPath());
wxFileConfig copyConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());

theConfig.Write("Astade/EntryAction", copyConfig.Read("Astade/EntryAction"));
theConfig.Write("Astade/ExitAction", copyConfig.Read("Astade/ExitAction"));
theConfig.Write("Astade/Timeout", copyConfig.Read("Astade/Timeout"));

return aFileName;
