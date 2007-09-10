wxString TransitionType = myConfig->Read("Astade/TransitionType");

if (TransitionType=="Normal")
	return true;
else
	return false;