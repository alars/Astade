if (VirtualField && StaticField && AbstractField && InlineField)
	if (StaticField->IsChecked() || InlineField->IsChecked())
	{
		VirtualField->SetValue(false);
		AbstractField->SetValue(false);
	}
