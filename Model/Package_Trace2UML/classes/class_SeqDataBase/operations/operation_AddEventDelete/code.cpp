//~~ void AddEventDelete(int object1, int object2, wxString timeStamp, wxString threadID) [SeqDataBase] ~~
if (object2 == wxNOT_FOUND)
	return;

if (object1 == wxNOT_FOUND)
	itsEvents.push_back(SeqEvent(wxNOT_FOUND,object2,ID_GLOBALDELETE,wxEmptyString,timeStamp,threadID));
else
	itsEvents.push_back(SeqEvent(object1,object2,ID_DELETE,wxEmptyString,timeStamp,threadID));

itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 21;