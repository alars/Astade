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
	if (LookingForComponent->IsChecked() || LookingForAll->IsChecked())
		myAstadeSearch.AddOption(AdeSearch::Component);

	if (LookingForClass->IsChecked() || LookingForAll->IsChecked())
		myAstadeSearch.AddOption(AdeSearch::Class);

	if (LookingForOperation->IsChecked() || LookingForAll->IsChecked())
		myAstadeSearch.AddOption(AdeSearch::Operation);

	if (LookingForType->IsChecked() || LookingForAll->IsChecked())
		myAstadeSearch.AddOption(AdeSearch::Type);

	if (LookingForState->IsChecked() || LookingForAll->IsChecked())
		myAstadeSearch.AddOption(AdeSearch::State);

	if (LookingForUserCode->IsChecked() || LookingForAll->IsChecked())
		myAstadeSearch.AddOption(AdeSearch::UserCode);

	if (LookingForAttribute->IsChecked() || LookingForAll->IsChecked())
		myAstadeSearch.AddOption(AdeSearch::Attribute);

	if (LookingForParameter->IsChecked() || LookingForAll->IsChecked())
		myAstadeSearch.AddOption(AdeSearch::Parameter);

	if (FieldsToSearchName->IsChecked() || FieldsToSearchAll->IsChecked())
		myAstadeSearch.AddOption(AdeSearch::Name);

	if (FieldsToSearchDefault->IsChecked() || FieldsToSearchAll->IsChecked())
		myAstadeSearch.AddOption(AdeSearch::Default);

	if (FieldsToSearchDescription->IsChecked() || FieldsToSearchAll->IsChecked())
		myAstadeSearch.AddOption(AdeSearch::Description);

	if (FieldsToSearchType->IsChecked() || FieldsToSearchAll->IsChecked())
		myAstadeSearch.AddOption(AdeSearch::theType);

	if (FieldsToSearchUserCode->IsChecked() || FieldsToSearchAll->IsChecked())
		myAstadeSearch.AddOption(AdeSearch::theUserCode);

	if (OptionActiveComponentOnly->IsChecked())
		myAstadeSearch.AddOption(AdeSearch::activeComponentOnly);

	myAstadeSearch.AddOption(AdeSearch::SearchIsActive);
	dynamic_cast<AstadeFrame*>(GetParent())->Search();
}
