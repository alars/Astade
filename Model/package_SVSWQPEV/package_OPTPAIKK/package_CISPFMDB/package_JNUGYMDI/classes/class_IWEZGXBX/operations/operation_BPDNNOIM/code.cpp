wxFileConfig ownConfig(wxEmptyString,wxEmptyString,wxEmptyString,myFileName.GetFullPath());
wxString TransitionType = ownConfig.Read("Astade/TransitionType");

if (TransitionType=="Internal")
	return true;
else
	return false;