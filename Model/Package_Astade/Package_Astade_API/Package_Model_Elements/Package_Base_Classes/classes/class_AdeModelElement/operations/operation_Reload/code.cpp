delete myConfig;
if (myFileName.GetExt() == wxS("ini"))
	myConfig = new wxFileConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());
else
	myConfig = new wxFileConfig();
