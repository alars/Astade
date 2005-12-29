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

if (secondToken=="(!)")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	AddEventCreate(AddObject(firstToken),AddObject(thirdToken));
}
else
if (secondToken=="(X)")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	AddEventDelete(AddObject(firstToken),AddObject(thirdToken));
}
else
if (secondToken=="==>")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	AddEventCall(AddObject(firstToken),AddObject(thirdToken),aStringTokenizer.GetString());
}
else
if (secondToken=="<==")
{
	wxString thirdToken = aStringTokenizer.GetNextToken();
	AddEventReturn(AddObject(firstToken),AddObject(thirdToken),aStringTokenizer.GetString());
}
