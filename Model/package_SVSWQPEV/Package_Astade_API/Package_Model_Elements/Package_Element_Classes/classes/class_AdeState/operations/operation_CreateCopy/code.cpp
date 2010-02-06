wxFileName aFileName = AdeDirectoryElement::CreateCopy(parentPath); // let the base class do the main work

wxFileConfig theConfig(wxEmptyString, wxEmptyString, aFileName.GetFullPath());

theConfig.Write("Astade/EntryAction", myConfig->Read("Astade/EntryAction"));
theConfig.Write("Astade/ExitAction", myConfig->Read("Astade/ExitAction"));
theConfig.Write("Astade/Timeout", myConfig->Read("Astade/Timeout"));

return aFileName;