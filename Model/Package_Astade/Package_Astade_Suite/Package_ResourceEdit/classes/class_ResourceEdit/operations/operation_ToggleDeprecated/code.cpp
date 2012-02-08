if (DeprecatedField && DeprecatedEditField)
{
	DeprecatedEditField->Enable(DeprecatedField->IsChecked());

	if(DeprecatedField->IsChecked() && DeprecatedEditField->IsEmpty())
	{
		wxDateTime now = wxDateTime::Now();
		DeprecatedEditField->SetValue(wxS("Marked as deprecated since ") + now.Format(wxS("%c"), wxDateTime::UTC) + wxS(".\n Don't use it any more."));
	}
}
