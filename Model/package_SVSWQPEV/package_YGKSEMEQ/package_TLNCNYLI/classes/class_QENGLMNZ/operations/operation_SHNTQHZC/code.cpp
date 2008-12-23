if (event.IsChecked())
{
	FieldsToSearchName->Disable();
	FieldsToSearchType->Disable();
	FieldsToSearchDefault->Disable();
	FieldsToSearchUserCode->Disable();
	FieldsToSearchDescription->Disable();
}
else
{
	FieldsToSearchName->Enable();
	FieldsToSearchType->Enable();
	FieldsToSearchDefault->Enable();
	FieldsToSearchUserCode->Enable();
	FieldsToSearchDescription->Enable();
}