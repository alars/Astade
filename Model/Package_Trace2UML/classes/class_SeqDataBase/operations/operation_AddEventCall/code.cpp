//~~ void AddEventCall(int object1, int object2, const wxString& label, const wxString& timeStamp, int parsedEvent, const wxString& threadID) [SeqDataBase] ~~
if (object2 == wxNOT_FOUND)
	return;

wxString s = label;

if (object1 == wxNOT_FOUND)
{
	itsEvents.push_back(SeqEvent(wxNOT_FOUND,object2,ID_GLOBALCALL,s.Trim(true).Trim(false),timeStamp, threadID, parsedEvent));
	itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 17;
}
else
if (object1==object2)
{
	itsEvents.push_back(SeqEvent(object1,object2,ID_SELFCALL,s.Trim(true).Trim(false),timeStamp, threadID, parsedEvent));
	itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 25;
}
else
{
	itsEvents.push_back(SeqEvent(object1,object2,ID_CALL,s.Trim(true).Trim(false),timeStamp, threadID, parsedEvent));
	itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 17;
}