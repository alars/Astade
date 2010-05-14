myFileName.SetFullName(wxS("ModelNode.ini"));
wxFileConfig theConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());
theConfig.Write(wxS("Astade/Type"), GetType());
