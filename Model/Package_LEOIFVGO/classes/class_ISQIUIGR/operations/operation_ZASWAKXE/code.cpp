if (object1 == wxNOT_FOUND)
	itsEvents.push_back(SeqEvent(wxNOT_FOUND,object2,ID_GLOBALDELETE,wxEmptyString));
else
	itsEvents.push_back(SeqEvent(object1,object2,ID_DELETE,wxEmptyString));

itsEvents.push_back(SeqEvent(0,object2,ID_NOP,wxEmptyString));