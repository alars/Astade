wxFileConfig theConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());
wxString baseClasses;
theConfig.Read("Astade/AdditionalClasses", &baseClasses);
return baseClasses;
