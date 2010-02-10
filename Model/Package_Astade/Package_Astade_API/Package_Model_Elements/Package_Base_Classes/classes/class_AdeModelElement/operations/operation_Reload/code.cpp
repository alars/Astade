delete myConfig;
if (myFileName.GetExt()=="ini")
	myConfig = new wxFileConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());
else
	myConfig = new wxFileConfig();