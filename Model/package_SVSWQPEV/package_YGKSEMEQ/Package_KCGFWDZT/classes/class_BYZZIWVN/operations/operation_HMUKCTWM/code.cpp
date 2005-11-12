wxConfigBase::Get()->Write("Astade/ID","$I""d$");
wxConfigBase::Get()->Write("Astade/LastChanged",wxGetUTCTime());

int elementType;
wxConfigBase::Get()->Read("Astade/Type",&elementType);

if (NameEditField)
	wxConfigBase::Get()->Write("Astade/Name",NameEditField->GetValue());

if (TypeEditField)
	wxConfigBase::Get()->Write("Astade/CodingType",TypeEditField->GetValue());

if (AdditionalClassesEditField)
	wxConfigBase::Get()->Write("Astade/AdditionalClasses",AdditionalClassesEditField->GetValue());

if (DefaultEditField)
	wxConfigBase::Get()->Write("Astade/Default",DefaultEditField->GetValue());

if (DescriptionEditField)
	wxConfigBase::Get()->Write("Astade/Description",DescriptionEditField->GetValue());

if (Multiplicity)
	wxConfigBase::Get()->Write("Astade/Multiplicity",Multiplicity->GetValue());

if (AgregationType)
	wxConfigBase::Get()->Write("Astade/RelationType",AgregationType->GetValue());

if (Implementation)
	wxConfigBase::Get()->Write("Astade/Implementation",Implementation->GetValue());

if (InitialState)
	wxConfigBase::Get()->Write("Astade/InitialState",InitialState->GetValue());

if (action1)
	wxConfigBase::Get()->Write("Astade/Action1",action1->GetValue());

if (action2)
	wxConfigBase::Get()->Write("Astade/Action2",action2->GetValue());

if (ConstField)
{
	if (ConstField->IsChecked())
		wxConfigBase::Get()->Write("Astade/Const","yes");
	else
		wxConfigBase::Get()->Write("Astade/Const","no");
}

if (VirtualField)
{
	if (VirtualField->IsChecked())
		wxConfigBase::Get()->Write("Astade/Virtual","yes");
	else
		wxConfigBase::Get()->Write("Astade/Virtual","no");
}

if (StaticField)
{
	if (StaticField->IsChecked())
		wxConfigBase::Get()->Write("Astade/Static","yes");
	else
		wxConfigBase::Get()->Write("Astade/Static","no");
}

if (AbstractField)
{
	if (AbstractField->IsChecked())
		wxConfigBase::Get()->Write("Astade/Abstract","yes");
	else
		wxConfigBase::Get()->Write("Astade/Abstract","no");
}

if (m_private)
{
	if (m_private->GetValue())
	{
		elementType |= ITEM_IS_PRIVATE;
		elementType &= ~ITEM_IS_PROTECTED;
		elementType &= ~ITEM_IS_PUBLIC;
	}
	else
	if (m_public->GetValue())
	{
		elementType &= ~ITEM_IS_PRIVATE;
		elementType &= ~ITEM_IS_PROTECTED;
		elementType |= ITEM_IS_PUBLIC;
	}
	else
	if (m_protected->GetValue())
	{
		elementType &= ~ITEM_IS_PRIVATE;
		elementType |= ITEM_IS_PROTECTED;
		elementType &= ~ITEM_IS_PUBLIC;
	}

	wxConfigBase::Get()->Write("Astade/Type",elementType);
}

wxConfigBase::Get()->Flush();
Destroy();
