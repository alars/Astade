if ((object2 == wxNOT_FOUND) || (object1 == wxNOT_FOUND))
	return;

if (object1==object2)
	return;

wxString s = label;

if (timeStamp.size() > longestTimeStamp)
	longestTimeStamp = timeStamp.size();

itsEvents.push_back(SeqEvent(object1,object2,ID_TASKSWITCH,s.Trim(true).Trim(false),timeStamp));

itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 17;