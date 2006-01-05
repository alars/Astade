theLine.Trim(true).Trim(false);

if (theLine.empty())
	return;

if (theLine.GetChar(0)=='#')
{
	theLine.Remove(0,1);
	theLine.Trim(false);
	AddEventComment(theLine);
	return;
}

wxStringTokenizer aStringTokenizer(theLine);

wxString firstToken = aStringTokenizer.GetNextToken();

if (firstToken.IsNumber())
	firstToken = aStringTokenizer.GetNextToken();

wxString secondToken = aStringTokenizer.GetNextToken();

if (firstToken=="!")
{
	AddEventExist(AddObject(secondToken));
}
else
if (secondToken==">>>")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID = EnsureObject(firstToken);
	AddEventStateChange(ID,thirdToken);
}
else
if (secondToken=="-->")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID = EnsureObject(firstToken);
	AddEventReceive(ID,EnsureObject(thirdToken),aStringTokenizer.GetString());
}
else
if (secondToken==">--")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID = EnsureObject(firstToken);
	AddEventSend(ID,EnsureObject(thirdToken),aStringTokenizer.GetString());
}
else
if (secondToken=="(!)")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID = EnsureObject(firstToken);
	AddEventCreate(ID,AddObject(thirdToken));
}
else
if (secondToken=="(X)")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID = EnsureObject(firstToken);
	AddEventDelete(ID,EnsureObject(thirdToken));
}
else
if (secondToken=="==>")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID = EnsureObject(firstToken);
	AddEventCall(ID,EnsureObject(thirdToken),aStringTokenizer.GetString());
}
else
if (secondToken=="<==")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID = EnsureObject(firstToken);
	AddEventReturn(ID,EnsureObject(thirdToken),aStringTokenizer.GetString());
}
