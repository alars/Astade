if (indexBase == -1) // not yet initialized
	InitializeIcons();

wxFileConfig theConfig(wxEmptyString,wxEmptyString,wxEmptyString,myModelElement->GetFileName().GetFullPath());

wxString TransitionType = theConfig.Read("Astade/TransitionType");

if (TransitionType=="Self")
	return indexBase + 1;

if (TransitionType=="Internal")
	return indexBase + 2;

return indexBase;