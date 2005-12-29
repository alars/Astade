wxString s = label;

if (object1==object2)
	itsEvents.push_back(SeqEvent(object1,object2,ID_SELFCALL,s.Trim(true).Trim(false)));
else
	itsEvents.push_back(SeqEvent(object1,object2,ID_CALL,s.Trim(true).Trim(false)));