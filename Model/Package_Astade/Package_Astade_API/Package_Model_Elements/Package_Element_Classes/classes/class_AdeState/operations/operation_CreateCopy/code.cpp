wxFileName aFileName = AdeDirectoryElement::CreateCopy(parentPath); // let the base class do the main work

wxFileConfig theConfig(wxEmptyString, wxEmptyString, aFileName.GetFullPath());

theConfig.Write(wxS("Astade/EntryAction"), myConfig->Read(wxS("Astade/EntryAction")));
theConfig.Write(wxS("Astade/ExitAction"), myConfig->Read(wxS("Astade/ExitAction")));
theConfig.Write(wxS("Astade/Timeout"), myConfig->Read(wxS("Astade/Timeout")));

return aFileName;
