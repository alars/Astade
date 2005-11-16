wxFileConfig ownConfig(wxEmptyString,wxEmptyString,wxEmptyString,myFileName.GetFullPath());
wxString TransitionType = ownConfig.Read("Astade/TransitionType");

if (TransitionType=="Normal")
	return AdeFileElement::GetType() + 2;

if (TransitionType=="Self")
	return AdeFileElement::GetType() + 1;

return AdeFileElement::GetType() + 0;
