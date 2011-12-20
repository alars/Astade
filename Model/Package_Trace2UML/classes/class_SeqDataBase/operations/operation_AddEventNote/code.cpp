//~~ void AddEventNote(int object1, const wxString& label, const wxString& timeStamp) [SeqDataBase] ~~
if (object1 == wxNOT_FOUND)
	return;

wxString s = label;

itsEvents.push_back(SeqEvent(object1,wxNOT_FOUND,ID_NOTE,s.Trim(true).Trim(false),timeStamp,wxEmptyString));

itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 200;