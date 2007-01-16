wxFileConfig theConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());
theConfig.Write("Components/" + component.GetGUID(), true);