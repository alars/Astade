wxString inputLine = TextToFind->GetValue();

if (!inputLine.empty())
{
	int index = TextToFind->FindString(inputLine);

	if (index != wxNOT_FOUND)
		TextToFind->Delete(index);

	TextToFind->Insert(inputLine,0);

	if (TextToFind->GetCount() >= 30)
		TextToFind->Delete(29);
}