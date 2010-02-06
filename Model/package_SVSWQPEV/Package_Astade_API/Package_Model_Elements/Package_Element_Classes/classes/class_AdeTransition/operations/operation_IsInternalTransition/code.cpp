wxString TransitionType = myConfig->Read("Astade/TransitionType");

if (TransitionType=="Internal")
	return true;
else
	return false;