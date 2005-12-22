wxFileConfig theConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());
bool is = false;
theConfig.Read("Astade/LibClass",&is);
return is;