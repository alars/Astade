//~~ void AddEventTaskSwitch(int object1, int object2, const wxString& label, const wxString& timeStamp) [SeqDataBase] ~~
if ((object2 == wxNOT_FOUND) || (object1 == wxNOT_FOUND))
	return;

if (object1==object2)
	return;

wxString s = label;

itsEvents.push_back(SeqEvent(object1,object2,ID_TASKSWITCH,s.Trim(true).Trim(false),timeStamp,wxEmptyString));

itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 17;