wxFileConfig theConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());
bool is = false;
theConfig.Read("Astade/LibClass", &is);
if (is)
	return theConfig.Read("Astade/ClassInclude");
return wxEmptyString;
