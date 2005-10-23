if (VirtualField && StaticField && AbstractField)
	if (AbstractField->IsChecked())
	{
		VirtualField->SetValue(true);
		StaticField->SetValue(false);
	}