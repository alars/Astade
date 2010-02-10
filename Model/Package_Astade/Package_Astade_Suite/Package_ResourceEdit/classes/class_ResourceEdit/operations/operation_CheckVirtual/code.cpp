if (VirtualField && StaticField && AbstractField && InlineField)
	if (AbstractField->IsChecked())
	{
		VirtualField->SetValue(true);
		InlineField->SetValue(false);
		StaticField->SetValue(false);
	}
SetIcon();