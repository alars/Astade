theLine.Trim(true);
theLine.Trim(false);

if ((theLine.empty())||(theLine.GetChar(0)=='#'))
	return;

wxStringTokenizer aStringTokenizer(theLine);

wxString firstToken = aStringTokenizer.GetNextToken();

if (firstToken.IsNumber())
	firstToken = aStringTokenizer.GetNextToken();

if (firstToken.empty())
	return;

if (firstToken=="!" || firstToken=="(!)")
{
	// Global Create
	wxString secondToken = aStringTokenizer.GetNextToken();
	if (secondToken.empty())
		return;
	if ((classes.Index(secondToken)==wxNOT_FOUND) && (classes.GetCount()<32))
		classes.Add(secondToken);

	itsEvents.push_back(SeqEvent(wxEmptyString,secondToken,ID_GLOBALCREATE));
}
else
{
	if ((classes.Index(firstToken)==wxNOT_FOUND) && (classes.GetCount()<32))
		classes.Add(firstToken);
}