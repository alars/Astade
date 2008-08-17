if (object2 == wxNOT_FOUND)
	return;

if (timeStamp.size() > longestTimeStamp)
	longestTimeStamp = timeStamp.size();

if (object1 == wxNOT_FOUND)
	itsEvents.push_back(SeqEvent(wxNOT_FOUND,object2,ID_GLOBALCREATE,wxEmptyString,timeStamp));
else
	itsEvents.push_back(SeqEvent(object1,object2,ID_CREATE,wxEmptyString,timeStamp));

itsEvents.back().time = itsEvents[itsEvents.size()-2].time + GetClassBoxHight();

itsEvents.push_back(SeqEvent(0,object2,ID_CLASSBOX,wxEmptyString,timeStamp));

itsEvents.back().time = itsEvents[itsEvents.size()-2].time;