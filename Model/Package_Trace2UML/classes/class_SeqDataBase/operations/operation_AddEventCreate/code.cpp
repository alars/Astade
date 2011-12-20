//~~ void AddEventCreate(int object1, int object2, const wxString& timeStamp, const wxString& threadID) [SeqDataBase] ~~
if (object2 == wxNOT_FOUND)
	return;

if (object1 == wxNOT_FOUND)
	itsEvents.push_back(SeqEvent(wxNOT_FOUND,object2,ID_GLOBALCREATE,wxEmptyString,timeStamp,threadID));
else
	itsEvents.push_back(SeqEvent(object1,object2,ID_CREATE,wxEmptyString,timeStamp,threadID));

itsEvents.back().time = itsEvents[itsEvents.size()-2].time + GetClassBoxHeight();

itsEvents.push_back(SeqEvent(0,object2,ID_CLASSBOX,wxEmptyString,timeStamp,threadID));

itsEvents.back().time = itsEvents[itsEvents.size()-2].time;
