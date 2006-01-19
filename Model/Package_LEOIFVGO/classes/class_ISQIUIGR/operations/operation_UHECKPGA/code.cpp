if (object1 == wxNOT_FOUND)
	return;

wxString s = label;

if (timeStamp.size() > longestTimeStamp)
	longestTimeStamp = timeStamp.size();

itsEvents.push_back(SeqEvent(object1,wxNOT_FOUND,ID_STATECHANGE,s.Trim(true).Trim(false),timeStamp));
