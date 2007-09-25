if (innerBracket)
	return;

file_position fp = p1.get_position();
long startPosition = g_Results->XYToPosition(fp.column-1,fp.line-1);

fp = p2.get_position();
long endPosition = g_Results->XYToPosition(fp.column-1,fp.line-1);

long insertionPoint = g_Results->GetInsertionPoint();

wxFont aFont(*defaultFont);
aFont.SetWeight(wxFONTWEIGHT_BOLD);

if ((insertionPoint > startPosition) && (insertionPoint < endPosition))
{
	innerBracket = true;
	g_Results->SetStyle(startPosition, startPosition+1, wxTextAttr(wxNullColour,wxNullColour,aFont));
	g_Results->SetStyle(endPosition-1, endPosition, wxTextAttr(wxNullColour,wxNullColour,aFont));
}