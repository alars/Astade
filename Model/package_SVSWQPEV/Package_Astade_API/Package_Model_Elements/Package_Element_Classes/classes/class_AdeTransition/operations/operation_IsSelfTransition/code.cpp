wxString TransitionType = myConfig->Read("Astade/TransitionType");

if (TransitionType=="Self")
	return true;
else
	return false;