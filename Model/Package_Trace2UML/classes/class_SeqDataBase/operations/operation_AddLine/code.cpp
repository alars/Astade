//~~ void AddLine(wxString theLine) [SeqDataBase] ~~

wxString pattern("Trace|");

int a = theLine.Find(pattern);

if (a >= 0)
{
    theLine.Remove(0,a+pattern.Length());
}

theLine.Trim(true).Trim(false);

if (theLine.empty())
    return;

wxString timestamp;
wxString threadID;
int b;

a = theLine.Find('[');
b = theLine.Find(']', true);

if ((char)theLine.GetChar(0) != '#')
{
    if (a >= 0 && a < b)
    {
        timestamp = theLine.Mid(a, b - a + 1);
        theLine.Remove(a, timestamp.size());
        theLine.Trim(true).Trim(false);
    }

    a = theLine.Find('{');
    b = theLine.Find('}', true);

    if (a >= 0 && a < b)
    {
        threadID = theLine.Mid(a, b - a + 1);
        theLine.Remove(a, threadID.size());
        theLine.Trim(true).Trim(false);
    }
}

switch ((char)theLine.GetChar(0))
{
    case '%':
        theLine.Remove(0, 1);
        theLine.Trim(false);
        {
            wxString aString;
            if (AddConnection(theLine))
                aString = wxS(";Connect OK: ")+theLine;
            else
                aString = wxS(";Connect FAIL: ")+theLine;
            AddEventCommentOnly(aString);
            }
        return;

    case '$':
        theLine.Remove(0, 1);
        theLine.Trim(false);
        FindSignal(theLine);
        return;

    case '_':
        theLine.Remove(0, 1);
        theLine.Trim(false);
        RemoveConnection(theLine);
        return;

    case '&':
        theLine.Remove(0, 1);
        theLine.Trim(false);
        FindSlot(theLine);
        return;

    case '#':
        theLine.Remove(0, 1);
        theLine.Trim(false);
        AddEventComment(theLine);
        return;

    case ';':
        AddEventCommentOnly(theLine);
        return;

    case '>':
        theLine.Remove(0, 1);
        theLine = wxS("??? ==> ") + theLine;
        break;
        
    case '+':
        theLine.Remove(0, 1);
        theLine = wxS("??? (!) ") + theLine;
        break;
        
    case '-':
        theLine.Remove(0, 1);
        theLine = wxS("??? (X) ") + theLine;
        break;
        
    case '<':
        theLine.Remove(0, 1);
        theLine = wxS("ret ") + theLine;
        break;
}

if ((timestamp.size() + threadID.size()) > longestTimeStamp)
    longestTimeStamp = (timestamp.size() + threadID.size());

wxStringTokenizer aStringTokenizer(theLine);

wxString firstToken = aStringTokenizer.GetNextToken();
wxString eventNumber;

if (firstToken.IsNumber())
{
    eventNumber = firstToken;
    firstToken = aStringTokenizer.GetNextToken();
}

wxString secondToken = aStringTokenizer.GetNextToken();

if (firstToken == wxS("..."))
{
    AddEventPause();
    return;
}

if (secondToken == wxS("==>"))
{
    wxString thirdToken = aStringTokenizer.GetNextToken();
    int ID;
    if (firstToken == wxS("???"))
        ID = runningObject(threadID);
    else
        ID = EnsureObject(firstToken);
    long parsedEventNumber;
    eventNumber.ToLong(&parsedEventNumber);
    AddEventCall(ID, EnsureObject(thirdToken), aStringTokenizer.GetString(), timestamp, parsedEventNumber, threadID);
}
else if (secondToken == wxS("<=="))
{
    wxString thirdToken = aStringTokenizer.GetNextToken();
    int ID;
    if (firstToken == wxS("???"))
        ID = prevRunningObject(threadID);
    else
        ID = EnsureObject(firstToken);
        
    int ID2;
    if (thirdToken == wxS("???"))
        ID2 = runningObject(threadID);
    else
        ID2 = EnsureObject(thirdToken);
        
    AddEventReturn(ID, ID2, aStringTokenizer.GetString(), timestamp, threadID);
}
else if (firstToken.Left(4) == wxS("ret("))
{
    long number;
    if (firstToken.Mid(4,firstToken.Len()-5).ToLong(&number))
        AddEventRelReturn(number, secondToken, timestamp, threadID);
}
else if (firstToken.Left(3) == wxS("ret"))
{
    AddEventReturn(prevRunningObject(threadID), runningObject(threadID), secondToken, timestamp, threadID);
}
else if (firstToken == wxS("!"))
{
    AddEventExist(AddObject(secondToken));
}
else if (secondToken == wxS(">>>"))
{
    wxString thirdToken = aStringTokenizer.GetNextToken();
    int ID = EnsureObject(firstToken);
    AddEventStateChange(ID, thirdToken, timestamp);
}
else if (secondToken == wxS("note:"))
{
    int ID = EnsureObject(firstToken);
    AddEventNote(ID, aStringTokenizer.GetString(), timestamp);
}
else if (secondToken == wxS("ref:"))
{
    int ID = EnsureObject(firstToken);
    AddEventRef(ID, aStringTokenizer.GetString(), timestamp);
}
else if ((secondToken == wxS("-->")) or (secondToken == wxS("-=>")))
{
    wxString thirdToken = aStringTokenizer.GetNextToken();
    int ID  = wxNOT_FOUND;
    int ID2 = EnsureObject(thirdToken);

    wxString foundLabel = aStringTokenizer.GetString();

    if (firstToken != wxS("???") && firstToken != wxS("*"))
    {
        ID = EnsureObject(firstToken);
        if (ID2 >= 0 && ID2 < MAXCLASSCOUNT)
            for (std::list<int>::iterator it = eventQueue[ID2].begin();
                    it != eventQueue[ID2].end(); ++it)
                if (itsEvents[*it].sourceObject == ID &&
                    itsEvents[*it].label == foundLabel.Trim(true).Trim(false))
                {
                    eventQueue[ID2].erase(it);
                    break;
                }
    }
    else if (ID2 >= 0 && ID2 < MAXCLASSCOUNT)
    {
        for (std::list<int>::iterator it = eventQueue[ID2].begin();
                it != eventQueue[ID2].end(); ++it)
        {
            if (itsEvents[*it].label == foundLabel.Trim(true).Trim(false))
            {
                ID = itsEvents[*it].sourceObject;
                eventQueue[ID2].erase(it);
                break;
            }
            else if (itsEvents[*it].destinationObject == ID2)
            {
                foundLabel = itsEvents[*it].label;
                ID = itsEvents[*it].sourceObject;
                eventQueue[ID2].erase(it);
                break;
            }
        }
    }

    AddEventReceive(ID, ID2, foundLabel, timestamp, threadID, secondToken == wxS("-=>"));
}
else if (secondToken == wxS("<=>")) // TaskSwitch
{
    wxString thirdToken = aStringTokenizer.GetNextToken();
    int ID1 = EnsureObject(firstToken);
    int ID2 = EnsureObject(thirdToken);
    AddEventTaskSwitch(ID1, ID2, aStringTokenizer.GetString(), timestamp);
}
else if ((secondToken == wxS(">->")) || (secondToken == wxS(">=>")))
{
    wxString thirdToken = aStringTokenizer.GetNextToken();
    int ID1 = EnsureObject(firstToken);
    int ID2 = EnsureObject(thirdToken);
    AddEventSend(ID1, ID2, aStringTokenizer.GetString(), timestamp, threadID);
    AddEventReceive(ID1, ID2, aStringTokenizer.GetString(), timestamp, threadID, secondToken == wxS(">=>"));
}
else if (secondToken == wxS(">--"))
{
    wxString thirdToken = aStringTokenizer.GetNextToken();
    int ID1 = EnsureObject(firstToken);
    if (ID1 != wxNOT_FOUND)
    {
        int ID2 = EnsureObject(thirdToken);
        if (ID2 >= 0 && ID2 < MAXCLASSCOUNT)
            eventQueue[ID2].push_back(itsEvents.size());
        AddEventSend(ID1, ID2, aStringTokenizer.GetString(), timestamp, threadID);
    }
}
else if (secondToken == wxS("(!)"))
{
    wxString thirdToken = aStringTokenizer.GetNextToken();
    int ID;
    if (firstToken == wxS("???"))
        ID = runningObject(threadID);
    else
        ID = EnsureObject(firstToken);
    AddEventCreate(ID, AddObject(thirdToken), timestamp, threadID);
}
else if (secondToken == wxS("(X)"))
{
    wxString thirdToken = aStringTokenizer.GetNextToken();
    int ID;
    if (firstToken == wxS("???"))
        ID = runningObject(threadID);
    else
        ID = EnsureObject(firstToken);
    AddEventDelete(ID, EnsureObject(thirdToken), timestamp, threadID);
}
