//~~ wxString GetLabel(int eventNumber) [SeqDataBase] ~~
if ((eventNumber < 0) ||
	(static_cast<unsigned>(eventNumber) >= itsEvents.size()))
	return wxEmptyString;
return itsEvents[eventNumber].label;