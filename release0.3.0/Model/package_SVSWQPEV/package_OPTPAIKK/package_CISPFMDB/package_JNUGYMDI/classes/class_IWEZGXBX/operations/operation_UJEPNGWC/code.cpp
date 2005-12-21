wxFileConfig theConfig(wxEmptyString,wxEmptyString,wxEmptyString,myFileName.GetFullPath());

wxString TransitionType = theConfig.Read("Astade/TransitionType");

if (TransitionType=="Self")
	return 56;

if (TransitionType=="Internal")
	return 55;

return 53;