if (object2 == wxNOT_FOUND)
	return;

if (object1 == wxNOT_FOUND)
	itsEvents.push_back(SeqEvent(wxNOT_FOUND,object2,ID_GLOBALCREATE,wxEmptyString));
else
	itsEvents.push_back(SeqEvent(object1,object2,ID_CREATE,wxEmptyString));

itsEvents.push_back(SeqEvent(0,object2,ID_CLASSBOX,wxEmptyString));