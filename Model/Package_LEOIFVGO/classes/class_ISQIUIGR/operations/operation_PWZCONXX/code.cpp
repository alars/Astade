int object1, object2 = wxNOT_FOUND;

for (std::vector<SeqEvent>::reverse_iterator it = itsEvents.rbegin(); it != itsEvents.rend(); it++)
{
	if ((*it).eventNumber == RelativeNumber)
	{
		object1 = (*it).sourceObject;
		object2 = (*it).destinationObject;
		break;
	}
}

if (object2 == wxNOT_FOUND)
	return;

wxString s = label;

if (timeStamp.size() > longestTimeStamp)
	longestTimeStamp = timeStamp.size();

if (object1 == wxNOT_FOUND)
{
	if (s.empty())
	{
		itsEvents.push_back(SeqEvent(wxNOT_FOUND,object2,ID_GLOBALRETURN,s,timeStamp));
		itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 8;
	}
	else
	{
		itsEvents.push_back(SeqEvent(wxNOT_FOUND,object2,ID_GLOBALRETURN,s.Trim(true).Trim(false),timeStamp));
		itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 17;
	}
}
else
if (object1 == object2)
{
	itsEvents.push_back(SeqEvent(object1,object2,ID_SELFRETURN,s.Trim(true).Trim(false),timeStamp));
	itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 8;
}
else
{
	if (s.empty())
	{
		itsEvents.push_back(SeqEvent(object1,object2,ID_RETURN,s,timeStamp));
		itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 8;
	}
	else
	{
		itsEvents.push_back(SeqEvent(object1,object2,ID_RETURN,s.Trim(true).Trim(false),timeStamp));
		itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 17;
	}
}