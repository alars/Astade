if ((object2 == wxNOT_FOUND) || (object1 == wxNOT_FOUND))
	return;

wxString s = label;

if (timeStamp.size() > longestTimeStamp)
	longestTimeStamp = timeStamp.size();

if (object1==object2)
	itsEvents.push_back(SeqEvent(object1,object2,ID_SELFRECEIVE,s.Trim(true).Trim(false),timeStamp));
else
	itsEvents.push_back(SeqEvent(object1,object2,ID_RECEIVE,s.Trim(true).Trim(false),timeStamp));

itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 10;