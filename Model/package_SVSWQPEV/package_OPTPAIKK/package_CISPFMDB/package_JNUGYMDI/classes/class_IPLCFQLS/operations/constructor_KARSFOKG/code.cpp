myFileName.SetFullName("ModelNode.ini");
wxFileConfig theConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());
theConfig.Write("Astade/Type",GetType());