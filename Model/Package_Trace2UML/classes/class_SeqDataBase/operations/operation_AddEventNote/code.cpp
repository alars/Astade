//~~ void AddEventNote(int object1, const wxString& label, const wxString& timeStamp) [SeqDataBase] ~~
if (object1 == wxNOT_FOUND)
	return;

wxString s = label;

if (timeStamp.size() > longestTimeStamp)
	longestTimeStamp = timeStamp.size();

itsEvents.push_back(SeqEvent(object1,wxNOT_FOUND,ID_NOTE,s.Trim(true).Trim(false),timeStamp));

if (s.size() < 10)
    itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 24;
else if (s.size() < 21)
    itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 35;
else if (s.size() < 32)
    itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 47;
else if (s.size() < 43)
    itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 58;
else if (s.size() < 54)
    itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 70;
else if (s.size() < 65)
    itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 81;
else
    itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 93;
