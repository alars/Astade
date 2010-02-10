if (VirtualField && StaticField && AbstractField && InlineField)
{
	if (VirtualField->IsChecked())
	{
		InlineField->SetValue(false);
		StaticField->SetValue(false);
	}
	else
	{
		AbstractField->SetValue(false);
	}
}
SetIcon();
