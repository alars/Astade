wxFileConfig theConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());
theConfig.Write(wxS("Components/") + component.GetGUID(), true);
