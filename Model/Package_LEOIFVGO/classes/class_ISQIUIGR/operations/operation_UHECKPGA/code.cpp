wxString s = label;

if (object1 == object2)
	itsEvents.push_back(SeqEvent(object1,object2,ID_SELFRETURN,s.Trim(true).Trim(false)));
else
	itsEvents.push_back(SeqEvent(object1,object2,ID_RETURN,s.Trim(true).Trim(false)));