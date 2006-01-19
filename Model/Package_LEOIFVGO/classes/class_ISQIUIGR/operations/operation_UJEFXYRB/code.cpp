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
wxString timestamp;

if (firstToken.IsNumber())
	firstToken = aStringTokenizer.GetNextToken();

if (firstToken.GetChar(0)=='[')
{
	timestamp = firstToken;
	firstToken = aStringTokenizer.GetNextToken();
}

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
	AddEventStateChange(ID,thirdToken,timestamp);
}
else
if (secondToken=="-->")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID = EnsureObject(firstToken);
	AddEventReceive(ID,EnsureObject(thirdToken),aStringTokenizer.GetString(),timestamp);
}
else
if (secondToken==">--")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID = EnsureObject(firstToken);
	AddEventSend(ID,EnsureObject(thirdToken),aStringTokenizer.GetString(),timestamp);
}
else
if (secondToken=="(!)")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID = EnsureObject(firstToken);
	AddEventCreate(ID,AddObject(thirdToken),timestamp);
}
else
if (secondToken=="(X)")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID = EnsureObject(firstToken);
	AddEventDelete(ID,EnsureObject(thirdToken),timestamp);
}
else
if (secondToken=="==>")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID = EnsureObject(firstToken);
	AddEventCall(ID,EnsureObject(thirdToken),aStringTokenizer.GetString(),timestamp);
}
else
if (secondToken=="<==")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	int ID = EnsureObject(firstToken);
	AddEventReturn(ID,EnsureObject(thirdToken),aStringTokenizer.GetString(),timestamp);
}
