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

if (action3)
	wxConfigBase::Get()->Write("Astade/Action3",action3->GetValue());

if (action4)
	wxConfigBase::Get()->Write("Astade/Action4",action4->GetValue());

if (entryAction)
	wxConfigBase::Get()->Write("Astade/EntryAction",entryAction->GetValue());

if (exitAction)
	wxConfigBase::Get()->Write("Astade/ExitAction",exitAction->GetValue());

if (transitionType)
	wxConfigBase::Get()->Write("Astade/TransitionType",transitionType->GetValue());

if (eventType)
	wxConfigBase::Get()->Write("Astade/EventType",eventType->GetValue());

if (destinationEditField)
	wxConfigBase::Get()->Write("Astade/DestinationState",destinationEditField->GetValue());

if (guardEditField)
	wxConfigBase::Get()->Write("Astade/Guard",guardEditField->GetValue());

if (triggerEditField)
	wxConfigBase::Get()->Write("Astade/Trigger",triggerEditField->GetValue());

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
