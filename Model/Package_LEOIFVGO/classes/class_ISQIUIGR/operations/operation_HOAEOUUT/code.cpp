if ((object2 == wxNOT_FOUND) || (object1 == wxNOT_FOUND))
	return;

if (object1==object2)
	itsEvents.push_back(SeqEvent(object1,object2,ID_SELFSEND,wxEmptyString));
else
	itsEvents.push_back(SeqEvent(object1,object2,ID_SEND,wxEmptyString));