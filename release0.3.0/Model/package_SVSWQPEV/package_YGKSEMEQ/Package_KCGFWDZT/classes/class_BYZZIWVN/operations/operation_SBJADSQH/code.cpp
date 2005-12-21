if (VirtualField && StaticField && AbstractField)
	if (VirtualField->IsChecked())
	{
		StaticField->SetValue(false);
	}
	else
	{
		AbstractField->SetValue(false);
	}