if (object1 == wxNOT_FOUND)
	return;

if (itsEvents.empty())
	itsEvents.push_back(SeqEvent(wxNOT_FOUND,wxNOT_FOUND,ID_NOP,wxEmptyString,wxEmptyString));
else
	if (itsEvents.back().eventID==ID_COMMENT)
		itsEvents.push_back(SeqEvent(wxNOT_FOUND,wxNOT_FOUND,ID_NOP,wxEmptyString,wxEmptyString));

itsEvents.push_back(SeqEvent(wxNOT_FOUND,object1,ID_EXIST,wxEmptyString,wxEmptyString));