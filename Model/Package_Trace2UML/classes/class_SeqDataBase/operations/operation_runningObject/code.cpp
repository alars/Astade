//~~ int runningObject(const wxString& threadID) [SeqDataBase] ~~
for (std::vector<SeqEvent>::reverse_iterator it = itsEvents.rbegin(); it != itsEvents.rend(); it++)
{
    if ((*it).threadID == threadID)
    {
        if ((*it).eventID == ID_CALL)
            return (*it).destinationObject;
        if ((*it).eventID == ID_RETURN)
            return (*it).sourceObject;
    }
}
return wxNOT_FOUND;