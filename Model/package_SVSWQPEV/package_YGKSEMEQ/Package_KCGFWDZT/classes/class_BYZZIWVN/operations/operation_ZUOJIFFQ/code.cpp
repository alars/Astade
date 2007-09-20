if (DeprecatedField && DeprecatedEditField)
{
	DeprecatedEditField->Enable(DeprecatedField->IsChecked());

	if(DeprecatedField->IsChecked() && DeprecatedEditField->IsEmpty())
	{
		wxDateTime now = wxDateTime::Now();
		DeprecatedEditField->SetValue("Marked as deprecated since " + now.Format("%c", wxDateTime::UTC) + ".\n Don't use it any more.");
	}
}