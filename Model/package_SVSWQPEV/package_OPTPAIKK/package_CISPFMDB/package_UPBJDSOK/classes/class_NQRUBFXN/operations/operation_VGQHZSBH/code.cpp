wxFileConfig theConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());
theConfig.DeleteEntry("Components/" + component.GetGUID(), true);