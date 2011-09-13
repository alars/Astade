theLine.Trim(true).Trim(false);

if (theLine.empty())
	return;

if (theLine.GetChar(0) == '#')
{
	theLine.Remove(0, 1);
	theLine.Trim(false);
	AddEventComment(theLine);
	return;
}

if (theLine.GetChar(0) == ';')
{
	AddEventCommentOnly(theLine);
	return;
}

wxString timestamp;
int a = theLine.Find('[');
int b = theLine.Find(']', true);

if (a >= 0 && a < b)
{
	timestamp = theLine.Mid(a, b - a + 1);
	theLine.Remove(a, timestamp.size());
}

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
	int ID = EnsureObject(firstToken);
	long parsedEventNumber;
	eventNumber.ToLong(&parsedEventNumber);
	AddEventCall(ID, EnsureObject(thirdToken), aStringTokenizer.GetString(), timestamp, parsedEventNumber);
}
else if (secondToken == wxS("<=="))
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID = EnsureObject(firstToken);
	AddEventReturn(ID, EnsureObject(thirdToken), aStringTokenizer.GetString(), timestamp);
}
else if (firstToken.Left(4) == wxS("ret("))
{
	long number;
	if (firstToken.Mid(4,firstToken.Len()-5).ToLong(&number))
		AddEventRelReturn(number, secondToken, timestamp);
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
else if (secondToken == wxS("-->"))
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
					itsEvents[*it].label == foundLabel)
				{
					eventQueue[ID2].erase(it);
					break;
				}
	}
	else if (ID2 >= 0 && ID2 < MAXCLASSCOUNT)
	{
		for (std::list<int>::iterator it = eventQueue[ID2].begin();
				it != eventQueue[ID2].end(); ++it)
			if (itsEvents[*it].label == foundLabel)
			{
				ID = itsEvents[*it].sourceObject;
				eventQueue[ID2].erase(it);
				break;
			}
	}

	AddEventReceive(ID, ID2, foundLabel, timestamp);
}
else if (secondToken == wxS("<=>")) // TaskSwitch
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID1 = EnsureObject(firstToken);
	int ID2 = EnsureObject(thirdToken);
	AddEventTaskSwitch(ID1, ID2, aStringTokenizer.GetString(), timestamp);
}
else if (secondToken == wxS(">->"))
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID1 = EnsureObject(firstToken);
	int ID2 = EnsureObject(thirdToken);
	AddEventSend(ID1, ID2, aStringTokenizer.GetString(), timestamp);
	AddEventReceive(ID1, ID2, aStringTokenizer.GetString(), timestamp);
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
		AddEventSend(ID1, ID2, aStringTokenizer.GetString(), timestamp);
	}
}
else if (secondToken == wxS("(!)"))
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID = EnsureObject(firstToken);
	AddEventCreate(ID, AddObject(thirdToken), timestamp);
}
else if (secondToken == wxS("(X)"))
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID = EnsureObject(firstToken);
	AddEventDelete(ID, EnsureObject(thirdToken), timestamp);
}
