//~~ void Save(wxCommandEvent& event) [ResourceEdit] ~~

int elementType;
wxConfigBase::Get()->Read(wxS("Astade/Type"), &elementType);

if (NameEditField)
	wxConfigBase::Get()->Write(wxS("Astade/Name"), NameEditField->GetValue().Trim());

if (TypeEditField)
	wxConfigBase::Get()->Write(wxS("Astade/CodingType"), TypeEditField->GetValue().Trim());

if (AdditionalClassesEditField)
	wxConfigBase::Get()->Write(wxS("Astade/AdditionalClasses"), AdditionalClassesEditField->GetValue().Trim());

if (DefaultEditField)
	wxConfigBase::Get()->Write(wxS("Astade/Default"), DefaultEditField->GetValue().Trim());

if (DescriptionEditField)
	wxConfigBase::Get()->Write(wxS("Astade/Description"), DescriptionEditField->GetValue().Trim());

if (ConstraintEditField)
	wxConfigBase::Get()->Write(wxS("Astade/Constraint"), ConstraintEditField->GetValue().Trim(true).Trim(false));

if (ReturnDescriptionEditField)
	wxConfigBase::Get()->Write(wxS("Astade/ReturnDescription"), ReturnDescriptionEditField->GetValue().Trim(true).Trim(false));

if (Multiplicity)
	wxConfigBase::Get()->Write(wxS("Astade/Multiplicity"), Multiplicity->GetValue().Trim());

if (AggregationType)
	wxConfigBase::Get()->Write(wxS("Astade/RelationType"), AggregationType->GetValue().Trim());

if (Implementation)
	wxConfigBase::Get()->Write(wxS("Astade/Implementation"), Implementation->GetValue().Trim());

if (InitialState)
	wxConfigBase::Get()->Write(wxS("Astade/InitialState"), InitialState->GetValue().Trim());

if (action1)
	wxConfigBase::Get()->Write(wxS("Astade/Action1"), action1->GetValue().Trim());

if (action2)
	wxConfigBase::Get()->Write(wxS("Astade/Action2"), action2->GetValue().Trim());

if (action3)
	wxConfigBase::Get()->Write(wxS("Astade/Action3"), action3->GetValue().Trim());

if (action4)
	wxConfigBase::Get()->Write(wxS("Astade/Action4"), action4->GetValue().Trim());

if (timeoutField)
	wxConfigBase::Get()->Write(wxS("Astade/Timeout"), timeoutField->GetValue().Trim());

if (templateField)
	wxConfigBase::Get()->Write(wxS("Astade/Template"), templateField->GetValue().Trim());

if (entryAction)
	wxConfigBase::Get()->Write(wxS("Astade/EntryAction"), entryAction->GetValue().Trim());

if (exitAction)
	wxConfigBase::Get()->Write(wxS("Astade/ExitAction"), exitAction->GetValue().Trim());

if (transitionType)
	wxConfigBase::Get()->Write(wxS("Astade/TransitionType"), transitionType->GetValue().Trim());

if (eventType)
	wxConfigBase::Get()->Write(wxS("Astade/EventType"), eventType->GetValue().Trim());

if (coderSuffix)
	wxConfigBase::Get()->Write(wxS("Astade/CoderSuffix"), coderSuffix->GetValue().Trim());

if (destinationEditField)
	wxConfigBase::Get()->Write(wxS("Astade/DestinationState"), destinationEditField->GetValue().Trim());

if (guardEditField)
	wxConfigBase::Get()->Write(wxS("Astade/Guard"), guardEditField->GetValue().Trim());

if (triggerEditField)
	wxConfigBase::Get()->Write(wxS("Astade/Trigger"), triggerEditField->GetValue().Trim());

if (InitializerEditField)
	wxConfigBase::Get()->Write(wxS("Astade/Initializer"), InitializerEditField->GetValue().Trim());

if (DeclarationEditField)
	wxConfigBase::Get()->Write(wxS("Astade/Declaration"), DeclarationEditField->GetValue().Trim());

if (ClassIncludeEditField)
	wxConfigBase::Get()->Write(wxS("Astade/ClassInclude"), ClassIncludeEditField->GetValue().Trim());

if (InlineField)
	wxConfigBase::Get()->Write(wxS("Astade/Inline"), InlineField->IsChecked() ? wxS("yes") : wxS("no"));

if (codingLanguage)
{
    wxConfigBase::Get()->Write(wxS("Astade/CodingLanguage"), codingLanguage->GetValue());
	//This is for compatibility with older Versions
    wxConfigBase::Get()->Write(wxS("Astade/CCoded"), (codingLanguage->GetValue() == wxS("C") ? wxS("yes") : wxS("no")));
}

if (ConstField)
	wxConfigBase::Get()->Write(wxS("Astade/Const"), ConstField->IsChecked() ? wxS("yes") : wxS("no"));

if (inField)
	wxConfigBase::Get()->Write(wxS("Astade/InputParameter"), inField->IsChecked() ? wxS("yes") : wxS("no"));

if (outField)
	wxConfigBase::Get()->Write(wxS("Astade/OutputParameter"), outField->IsChecked() ? wxS("yes") : wxS("no"));

if (delegateField)
	wxConfigBase::Get()->Write(wxS("Astade/delegate"), delegateField->IsChecked() ? wxS("yes") : wxS("no"));

if (isNamespace)
	wxConfigBase::Get()->Write(wxS("Astade/IsNamespace"), isNamespace->IsChecked() ? wxS("yes") : wxS("no"));

if (DeprecatedField)
{
	wxConfigBase::Get()->Write(wxS("Astade/Deprecated"), DeprecatedField->IsChecked() ? wxS("yes") : wxS("no"));
	if (DeprecatedEditField && DeprecatedField->IsChecked())
		wxConfigBase::Get()->Write(wxS("Astade/DeprecatedDescription"), DeprecatedEditField->GetValue().Trim());
	else
		wxConfigBase::Get()->DeleteEntry(wxS("Astade/DeprecatedDescription"));
}

if (ExplicitField)
	wxConfigBase::Get()->Write(wxS("Astade/Explicit"), ExplicitField->IsChecked() ? wxS("yes") : wxS("no"));

if (StaticField)
	wxConfigBase::Get()->Write(wxS("Astade/Static"), StaticField->IsChecked() ? wxS("yes") : wxS("no"));

if (VirtualField)
	wxConfigBase::Get()->Write(wxS("Astade/Virtual"), VirtualField->IsChecked() ? wxS("yes") : wxS("no"));

if (AbstractField)
	wxConfigBase::Get()->Write(wxS("Astade/Abstract"), AbstractField->IsChecked() ? wxS("yes") : wxS("no"));

if (traceLevel)
	wxConfigBase::Get()->Write(wxS("Astade/Tracelevel"), traceLevel->GetValue());

if (DelegationObject)
	wxConfigBase::Get()->Write(wxS("Astade/DelegationObject"), DelegationObject->GetValue());

if (DelegationPort)
	wxConfigBase::Get()->Write(wxS("Astade/DelegationPort"), DelegationPort->GetValue());

if (InputPort)
	wxConfigBase::Get()->Write(wxS("Astade/InputPort"), InputPort->GetValue());

if (InputObject)
	wxConfigBase::Get()->Write(wxS("Astade/InputObject"), InputObject->GetValue());

if (OutputPort)
	wxConfigBase::Get()->Write(wxS("Astade/OutputPort"), OutputPort->GetValue());

if (OutputObject)
	wxConfigBase::Get()->Write(wxS("Astade/OutputObject"), OutputObject->GetValue());

if (m_private)
{
	if (m_private->GetValue())
	{
		elementType |= ITEM_IS_PRIVATE;
		elementType &= ~ITEM_IS_PROTECTED;
		elementType &= ~ITEM_IS_PUBLIC;
	}
	else if (m_public->GetValue())
	{
		elementType &= ~ITEM_IS_PRIVATE;
		elementType &= ~ITEM_IS_PROTECTED;
		elementType |= ITEM_IS_PUBLIC;
	}
	else if (m_protected->GetValue())
	{
		elementType &= ~ITEM_IS_PRIVATE;
		elementType |= ITEM_IS_PROTECTED;
		elementType &= ~ITEM_IS_PUBLIC;
	}
	wxConfigBase::Get()->Write(wxS("Astade/Type"), elementType);
}

if (bitsEditField)
	wxConfigBase::Get()->Write(wxS("Astade/Bits"), bitsEditField->GetValue().Trim());

wxConfigBase::Get()->Flush();

TouchAllParents();

Destroy();
