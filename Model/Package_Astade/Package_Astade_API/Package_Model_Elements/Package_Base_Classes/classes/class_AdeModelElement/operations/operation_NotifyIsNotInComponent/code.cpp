wxFileConfig theConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());
theConfig.DeleteEntry(wxS("Components/") + component.GetGUID(), true);
