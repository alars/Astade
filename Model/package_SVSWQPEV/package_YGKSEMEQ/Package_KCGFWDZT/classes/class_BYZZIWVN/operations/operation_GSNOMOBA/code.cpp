if (VirtualField && StaticField && AbstractField)
	if (StaticField->IsChecked())
	{
		VirtualField->SetValue(false);
		AbstractField->SetValue(false);
	}
