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
if (secondToken=="-->")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	AddEventReceive(EnsureObject(firstToken),EnsureObject(thirdToken),aStringTokenizer.GetString());
}
else
if (secondToken==">--")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	AddEventSend(EnsureObject(firstToken),EnsureObject(thirdToken),aStringTokenizer.GetString());
}
else
if (secondToken=="(!)")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	AddEventCreate(EnsureObject(firstToken),AddObject(thirdToken));
}
else
if (secondToken=="(X)")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	AddEventDelete(EnsureObject(firstToken),EnsureObject(thirdToken));
}
else
if (secondToken=="==>")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	AddEventCall(EnsureObject(firstToken),EnsureObject(thirdToken),aStringTokenizer.GetString());
}
else
if (secondToken=="<==")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	AddEventReturn(EnsureObject(firstToken),EnsureObject(thirdToken),aStringTokenizer.GetString());
}
