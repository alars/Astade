if (object2 == wxNOT_FOUND)
	return;

wxString s = label;

if (timeStamp.size() > longestTimeStamp)
	longestTimeStamp = timeStamp.size();

if (object1 == wxNOT_FOUND)
{
	itsEvents.push_back(SeqEvent(wxNOT_FOUND,object2,ID_GLOBALCALL,s.Trim(true).Trim(false),timeStamp));
	itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 17;
}
else
if (object1==object2)
{
	itsEvents.push_back(SeqEvent(object1,object2,ID_SELFCALL,s.Trim(true).Trim(false),timeStamp));
	itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 25;
}
else
{
	itsEvents.push_back(SeqEvent(object1,object2,ID_CALL,s.Trim(true).Trim(false),timeStamp));
	itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 17;
}