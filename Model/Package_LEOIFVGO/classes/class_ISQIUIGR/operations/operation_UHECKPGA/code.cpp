if (object1 == wxNOT_FOUND)
	return;

wxString s = label;

itsEvents.push_back(SeqEvent(object1,wxNOT_FOUND,ID_STATECHANGE,s.Trim(true).Trim(false)));
