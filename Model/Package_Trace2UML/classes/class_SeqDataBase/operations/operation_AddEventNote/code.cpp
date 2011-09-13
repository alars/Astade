if (object1 == wxNOT_FOUND)
	return;

wxString s = label;

if (timeStamp.size() > longestTimeStamp)
	longestTimeStamp = timeStamp.size();

itsEvents.push_back(SeqEvent(object1,wxNOT_FOUND,ID_NOTE,s.Trim(true).Trim(false),timeStamp));

if (s.size() < 10)
    itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 24;
else if (s.size() < 20)
    itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 38;
else if (s.size() < 30)
    itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 52;
else if (s.size() < 40)
    itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 66;
else
    itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 80;
