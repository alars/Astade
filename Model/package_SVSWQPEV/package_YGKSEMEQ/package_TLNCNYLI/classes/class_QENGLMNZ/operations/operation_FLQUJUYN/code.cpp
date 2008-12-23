wxString inputLine = TextToFind->GetValue();

if (!inputLine.empty())
{
	int index = TextToFind->FindString(inputLine);

	if (index != wxNOT_FOUND)
		TextToFind->Delete(index);

	TextToFind->Insert(inputLine,0);

	if (TextToFind->GetCount() >= 30)
		TextToFind->Delete(29);

	 TextToFind->SetValue(inputLine);
}

if (!OptionRegularExpression->IsChecked())
{
	inputLine.Replace("\\","\\\\");
	inputLine.Replace("[","\\[");
	inputLine.Replace("^","\\^");
	inputLine.Replace("$","\\$");
	inputLine.Replace(".","\\.");
	inputLine.Replace("|","\\|");
	inputLine.Replace("?","\\?");
	inputLine.Replace("*","\\*");
	inputLine.Replace("+","\\+");
	inputLine.Replace("(","\\(");
	inputLine.Replace(")","\\)");

	if (OptionWholeWordsOnly->IsChecked())
		inputLine = "[^_a-zA-Z0-9]" + inputLine + "[^_a-zA-Z0-9]";
}

bool isOk;

if (OptionCaseSensitive->IsChecked())
	isOk = myRegEx.Compile(inputLine, wxRE_EXTENDED);
else
	isOk = myRegEx.Compile(inputLine, wxRE_ICASE | wxRE_EXTENDED);

if (isOk)
	wxLogMessage(inputLine);