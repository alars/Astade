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

if (firstToken.IsNumber())
	firstToken = aStringTokenizer.GetNextToken();

wxString secondToken = aStringTokenizer.GetNextToken();

if (firstToken == "!")
{
	AddEventExist(AddObject(secondToken));
}
else if (secondToken == ">>>")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID = EnsureObject(firstToken);
	AddEventStateChange(ID, thirdToken, timestamp);
}
else if (secondToken == "-->")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID;
	int ID2 = EnsureObject(thirdToken);

	if (firstToken != "???" || eventQueue[ID2].empty())
		ID = EnsureObject(firstToken);
	else
		ID = eventQueue[ID2].front();

	if (ID2 >= 0 && ID2 < MAXCLASSCOUNT && !eventQueue[ID2].empty())
		eventQueue[ID2].pop_front();

	AddEventReceive(ID, ID2, aStringTokenizer.GetString(), timestamp);
}
else if (secondToken == "<=>") // TaskSwitch
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID1 = EnsureObject(firstToken);
	int ID2 = EnsureObject(thirdToken);
	AddEventTaskSwitch(ID1, ID2, aStringTokenizer.GetString(), timestamp);
}
else if (secondToken == ">->")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID1 = EnsureObject(firstToken);
	int ID2 = EnsureObject(thirdToken);
	AddEventSend(ID1, ID2, aStringTokenizer.GetString(), timestamp);
	AddEventReceive(ID1, ID2, aStringTokenizer.GetString(), timestamp);
}
else if (secondToken == ">--")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID1 = EnsureObject(firstToken);
	int ID2 = EnsureObject(thirdToken);
	if (ID2 >= 0 && ID2 < MAXCLASSCOUNT)
		eventQueue[ID2].push_back(ID1);
	AddEventSend(ID1, ID2, aStringTokenizer.GetString(), timestamp);
}
else if (secondToken == "(!)")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID = EnsureObject(firstToken);
	AddEventCreate(ID, AddObject(thirdToken), timestamp);
}
else if (secondToken == "(X)")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID = EnsureObject(firstToken);
	AddEventDelete(ID, EnsureObject(thirdToken), timestamp);
}
else if (secondToken == "==>")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID = EnsureObject(firstToken);
	AddEventCall(ID, EnsureObject(thirdToken), aStringTokenizer.GetString(), timestamp);
}
else if (secondToken == "<==")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID = EnsureObject(firstToken);
	AddEventReturn(ID, EnsureObject(thirdToken), aStringTokenizer.GetString(), timestamp);
}
