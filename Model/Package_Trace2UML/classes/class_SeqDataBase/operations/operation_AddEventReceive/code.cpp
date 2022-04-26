//~~ void AddEventReceive(int object1, int object2, const wxString& label, const wxString& timeStamp, const wxString& threadID, bool createFunction) [SeqDataBase] ~~
if (object2 == wxNOT_FOUND)
	return;

wxString s = label;

if (createFunction)
{
    if (object1 == wxNOT_FOUND)
        itsEvents.push_back(SeqEvent(object1,object2,ID_GLOBALRECEIVEFUNC,s.Trim(true).Trim(false),timeStamp,threadID));
    else if (object1 == object2)
        itsEvents.push_back(SeqEvent(object1,object2,ID_SELFRECEIVEFUNC,s.Trim(true).Trim(false),timeStamp,threadID));
    else
        itsEvents.push_back(SeqEvent(object1,object2,ID_RECEIVEFUNC,s.Trim(true).Trim(false),timeStamp,threadID));
}
else
{
    if (object1 == wxNOT_FOUND)
        itsEvents.push_back(SeqEvent(object1,object2,ID_GLOBALRECEIVE,s.Trim(true).Trim(false),timeStamp,threadID));
    else if (object1 == object2)
        itsEvents.push_back(SeqEvent(object1,object2,ID_SELFRECEIVE,s.Trim(true).Trim(false),timeStamp,threadID));
    else
        itsEvents.push_back(SeqEvent(object1,object2,ID_RECEIVE,s.Trim(true).Trim(false),timeStamp,threadID));
}

itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 13;
