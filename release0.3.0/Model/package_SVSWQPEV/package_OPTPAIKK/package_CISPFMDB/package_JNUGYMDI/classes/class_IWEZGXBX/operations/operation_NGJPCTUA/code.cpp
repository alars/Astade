wxFileConfig ownConfig(wxEmptyString,wxEmptyString,wxEmptyString,myFileName.GetFullPath());
wxString TransitionType = ownConfig.Read("Astade/TransitionType");

if (TransitionType=="Normal")
	return true;
else
	return false;