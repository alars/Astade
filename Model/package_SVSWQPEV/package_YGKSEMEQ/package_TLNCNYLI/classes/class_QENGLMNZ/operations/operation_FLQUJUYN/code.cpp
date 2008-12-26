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

myAstadeSearch.clear();

if (OptionCaseSensitive->IsChecked())
	isOk = myAstadeSearch.RegEx().Compile(inputLine, wxRE_EXTENDED);
else
	isOk = myAstadeSearch.RegEx().Compile(inputLine, wxRE_ICASE | wxRE_EXTENDED);

if (isOk)
{
	if (LookingForClass->IsChecked() || LookingForAll->IsChecked())
		myAstadeSearch.AddOption(AstadeSearch::Class);

	if (LookingForOperation->IsChecked() || LookingForAll->IsChecked())
		myAstadeSearch.AddOption(AstadeSearch::Operation);

	if (LookingForType->IsChecked() || LookingForAll->IsChecked())
		myAstadeSearch.AddOption(AstadeSearch::Type);

	if (LookingForUserCode->IsChecked() || LookingForAll->IsChecked())
		myAstadeSearch.AddOption(AstadeSearch::UserCode);

	if (LookingForAttribute->IsChecked() || LookingForAll->IsChecked())
		myAstadeSearch.AddOption(AstadeSearch::Attribute);

	if (LookingForParameter->IsChecked() || LookingForAll->IsChecked())
		myAstadeSearch.AddOption(AstadeSearch::Parameter);

	if (FieldsToSearchName->IsChecked() || FieldsToSearchAll->IsChecked())
		myAstadeSearch.AddOption(AstadeSearch::Name);

	if (FieldsToSearchDefault->IsChecked() || FieldsToSearchAll->IsChecked())
		myAstadeSearch.AddOption(AstadeSearch::Default);

	if (FieldsToSearchDescription->IsChecked() || FieldsToSearchAll->IsChecked())
		myAstadeSearch.AddOption(AstadeSearch::Description);

	if (FieldsToSearchType->IsChecked() || FieldsToSearchAll->IsChecked())
		myAstadeSearch.AddOption(AstadeSearch::theType);

	if (FieldsToSearchUserCode->IsChecked() || FieldsToSearchAll->IsChecked())
		myAstadeSearch.AddOption(AstadeSearch::theUserCode);

	myAstadeSearch.AddOption(AstadeSearch::SearchIsActive);
	dynamic_cast<AstadeFrame*>(GetParent())->Search();
}