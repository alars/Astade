//~~ int findReturn(int callID) [SeqDataBase] ~~
if (callID >= itsEvents.size())
    return callID;
    
int depth = 0;

int search = callID;

while (search < itsEvents.size())
{
    if (itsEvents[search].eventID == ID_CALL)
        depth++;
    else if (itsEvents[search].eventID == ID_GLOBALCALL)
        depth++;
    else if (itsEvents[search].eventID == ID_SELFCALL)
        depth++;
    else if (itsEvents[search].eventID == ID_RETURN)
        depth--;
    else if (itsEvents[search].eventID == ID_GLOBALRETURN)
        depth--;
    else if (itsEvents[search].eventID == ID_SELFRETURN)
        depth--;    
    
    if (depth < 1)
        return search;
        
    search++;
}
return itsEvents.size()-1;