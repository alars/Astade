if (object2 == wxNOT_FOUND)
	return;

wxString s = label;

if (object1 == wxNOT_FOUND)
	itsEvents.push_back(SeqEvent(wxNOT_FOUND,object2,ID_GLOBALRETURN,s.Trim(true).Trim(false)));
else
if (object1 == object2)
	itsEvents.push_back(SeqEvent(object1,object2,ID_SELFRETURN,s.Trim(true).Trim(false)));
else
	itsEvents.push_back(SeqEvent(object1,object2,ID_RETURN,s.Trim(true).Trim(false)));