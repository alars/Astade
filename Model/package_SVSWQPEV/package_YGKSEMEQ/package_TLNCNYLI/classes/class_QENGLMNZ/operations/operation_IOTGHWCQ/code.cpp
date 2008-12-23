if (event.IsChecked())
{
	OptionWholeWordsOnly->Disable();
	OptionMatchesNOT->Disable();
}
else
{
	OptionWholeWordsOnly->Enable();
	OptionMatchesNOT->Enable();
}