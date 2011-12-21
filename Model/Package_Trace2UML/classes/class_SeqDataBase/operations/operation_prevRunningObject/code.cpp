//~~ int prevRunningObject(const wxString& threadID) [SeqDataBase] ~~
int level = 0;
for (std::vector<SeqEvent>::reverse_iterator it = itsEvents.rbegin(); it != itsEvents.rend(); it++)
{
    if ((*it).threadID == threadID)
    {
        if (((*it).eventID == ID_RETURN) || ((*it).eventID == ID_GLOBALRETURN))
            level++;
        if (((*it).eventID == ID_CALL) || ((*it).eventID == ID_GLOBALCALL))
        {
            level--;
            if (level < 0)
                return (*it).sourceObject;
        }
    }
}
return wxNOT_FOUND;