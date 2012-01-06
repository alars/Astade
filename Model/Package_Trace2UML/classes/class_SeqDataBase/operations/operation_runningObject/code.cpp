//~~ int runningObject(const wxString& threadID) [SeqDataBase] ~~
for (std::vector<SeqEvent>::reverse_iterator it = itsEvents.rbegin(); it != itsEvents.rend(); it++)
{
    if ((*it).threadID == threadID)
    {
        if (((*it).eventID == ID_CALL) || ((*it).eventID == ID_GLOBALCALL) || ((*it).eventID == ID_SELFCALL))
            return (*it).destinationObject;
        if (((*it).eventID == ID_RETURN) || ((*it).eventID == ID_GLOBALRETURN) || ((*it).eventID == ID_SELFRETURN))
            return (*it).sourceObject;
    }
}
return wxNOT_FOUND;