//~~ int prevRunningObject(const wxString& threadID) [SeqDataBase] ~~
int level = 0;
for (std::vector<SeqEvent>::reverse_iterator it = itsEvents.rbegin(); it != itsEvents.rend(); it++)
{
    if ((*it).threadID == threadID)
    {
        if (((*it).eventID == ID_RETURN) || ((*it).eventID == ID_GLOBALRETURN) || ((*it).eventID == ID_SELFRETURN))
            level++;
        if (((*it).eventID == ID_CALL) || ((*it).eventID == ID_GLOBALCALL) || ((*it).eventID == ID_SELFCALL))
        {
            level--;
            if (level < 0)
                return (*it).sourceObject;
        }
    }
}
return wxNOT_FOUND;