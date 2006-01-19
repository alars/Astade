if (object2 == wxNOT_FOUND)
	return;

if (timeStamp.size() > longestTimeStamp)
	longestTimeStamp = timeStamp.size();

if (object1 == wxNOT_FOUND)
	itsEvents.push_back(SeqEvent(wxNOT_FOUND,object2,ID_GLOBALDELETE,wxEmptyString,timeStamp));
else
	itsEvents.push_back(SeqEvent(object1,object2,ID_DELETE,wxEmptyString,timeStamp));

itsEvents.push_back(SeqEvent(0,object2,ID_NOP,wxEmptyString,timeStamp));