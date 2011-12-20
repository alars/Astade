//~~ void AddEventSend(int object1, int object2, const wxString& label, const wxString& timeStamp, const wxString& threadID) [SeqDataBase] ~~
if (object1 == wxNOT_FOUND || object2 == wxNOT_FOUND)
	return;

wxString s = label;

if (object1 == object2)
	itsEvents.push_back(SeqEvent(object1,object2,ID_SELFSEND,s.Trim(true).Trim(false),timeStamp,threadID));
else
	itsEvents.push_back(SeqEvent(object1,object2,ID_SEND,s.Trim(true).Trim(false),timeStamp,threadID));

itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 13;
