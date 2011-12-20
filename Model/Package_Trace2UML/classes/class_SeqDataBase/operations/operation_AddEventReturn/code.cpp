//~~ void AddEventReturn(int object1, int object2, const wxString& label, const wxString& timeStamp) [SeqDataBase] ~~
if (object2 == wxNOT_FOUND)
	return;

wxString s = label;

if (object1 == wxNOT_FOUND)
{
	if (s.empty())
	{
		itsEvents.push_back(SeqEvent(wxNOT_FOUND,object2,ID_GLOBALRETURN,s,timeStamp,threadID));
		itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 8;
	}
	else
	{
		itsEvents.push_back(SeqEvent(wxNOT_FOUND,object2,ID_GLOBALRETURN,s.Trim(true).Trim(false),timeStamp,threadID));
		itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 17;
	}
}
else
if (object1 == object2)
{
	itsEvents.push_back(SeqEvent(object1,object2,ID_SELFRETURN,s.Trim(true).Trim(false),timeStamp,threadID));
	itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 8;
}
else
{
	if (s.empty())
	{
		itsEvents.push_back(SeqEvent(object1,object2,ID_RETURN,s,timeStamp,threadID));
		itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 8;
	}
	else
	{
		itsEvents.push_back(SeqEvent(object1,object2,ID_RETURN,s.Trim(true).Trim(false),timeStamp,threadID));
		itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 17;
	}
}