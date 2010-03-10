/* vi: set tabstop=4: */

int elementType;
wxConfigBase::Get()->Read("Astade/Type", &elementType);

if (NameEditField)
	wxConfigBase::Get()->Write("Astade/Name", NameEditField->GetValue().Trim());

if (TypeEditField)
	wxConfigBase::Get()->Write("Astade/CodingType", TypeEditField->GetValue().Trim());

if (AdditionalClassesEditField)
	wxConfigBase::Get()->Write("Astade/AdditionalClasses", AdditionalClassesEditField->GetValue().Trim());

if (DefaultEditField)
	wxConfigBase::Get()->Write("Astade/Default", DefaultEditField->GetValue().Trim());

if (DescriptionEditField)
	wxConfigBase::Get()->Write("Astade/Description", DescriptionEditField->GetValue().Trim());

if (ConstraintEditField)
	wxConfigBase::Get()->Write("Astade/Constraint", ConstraintEditField->GetValue().Trim(true).Trim(false));

if (ReturnDescriptionEditField)
	wxConfigBase::Get()->Write("Astade/ReturnDescription", ReturnDescriptionEditField->GetValue().Trim(true).Trim(false));

if (Multiplicity)
	wxConfigBase::Get()->Write("Astade/Multiplicity", Multiplicity->GetValue().Trim());

if (AggregationType)
	wxConfigBase::Get()->Write("Astade/RelationType", AggregationType->GetValue().Trim());

if (Implementation)
	wxConfigBase::Get()->Write("Astade/Implementation", Implementation->GetValue().Trim());

if (InitialState)
	wxConfigBase::Get()->Write("Astade/InitialState", InitialState->GetValue().Trim());

if (action1)
	wxConfigBase::Get()->Write("Astade/Action1", action1->GetValue().Trim());

if (action2)
	wxConfigBase::Get()->Write("Astade/Action2", action2->GetValue().Trim());

if (action3)
	wxConfigBase::Get()->Write("Astade/Action3", action3->GetValue().Trim());

if (action4)
	wxConfigBase::Get()->Write("Astade/Action4", action4->GetValue().Trim());

if (timeoutField)
	wxConfigBase::Get()->Write("Astade/Timeout", timeoutField->GetValue().Trim());

if (templateField)
	wxConfigBase::Get()->Write("Astade/Template", templateField->GetValue().Trim());

if (entryAction)
	wxConfigBase::Get()->Write("Astade/EntryAction", entryAction->GetValue().Trim());

if (exitAction)
	wxConfigBase::Get()->Write("Astade/ExitAction", exitAction->GetValue().Trim());

if (transitionType)
	wxConfigBase::Get()->Write("Astade/TransitionType", transitionType->GetValue().Trim());

if (eventType)
	wxConfigBase::Get()->Write("Astade/EventType", eventType->GetValue().Trim());

if (coderSuffix)
	wxConfigBase::Get()->Write("Astade/CoderSuffix", coderSuffix->GetValue().Trim());

if (destinationEditField)
	wxConfigBase::Get()->Write("Astade/DestinationState", destinationEditField->GetValue().Trim());

if (guardEditField)
	wxConfigBase::Get()->Write("Astade/Guard", guardEditField->GetValue().Trim());

if (triggerEditField)
	wxConfigBase::Get()->Write("Astade/Trigger", triggerEditField->GetValue().Trim());

if (InitializerEditField)
	wxConfigBase::Get()->Write("Astade/Initializer", InitializerEditField->GetValue().Trim());

if (DeclarationEditField)
	wxConfigBase::Get()->Write("Astade/Declaration", DeclarationEditField->GetValue().Trim());

if (ClassIncludeEditField)
	wxConfigBase::Get()->Write("Astade/ClassInclude", ClassIncludeEditField->GetValue().Trim());

if (InlineField)
	wxConfigBase::Get()->Write("Astade/Inline", InlineField->IsChecked() ? "yes" : "no");

if (isCCoded)
	wxConfigBase::Get()->Write("Astade/CCoded", isCCoded->IsChecked() ? "yes" : "no");

if (ConstField)
	wxConfigBase::Get()->Write("Astade/Const", ConstField->IsChecked() ? "yes" : "no");

if (inField)
	wxConfigBase::Get()->Write("Astade/InputParameter", inField->IsChecked() ? "yes" : "no");

if (outField)
	wxConfigBase::Get()->Write("Astade/OutputParameter", outField->IsChecked() ? "yes" : "no");

if (DeprecatedField)
{
	wxConfigBase::Get()->Write("Astade/Deprecated", DeprecatedField->IsChecked() ? "yes" : "no");
	if (DeprecatedEditField && DeprecatedField->IsChecked())
		wxConfigBase::Get()->Write("Astade/DeprecatedDescription", DeprecatedEditField->GetValue().Trim());
	else
		wxConfigBase::Get()->DeleteEntry("Astade/DeprecatedDescription");
}

if (ExplicitField)
	wxConfigBase::Get()->Write("Astade/Explicit", ExplicitField->IsChecked() ? "yes" : "no");

if (StaticField)
	wxConfigBase::Get()->Write("Astade/Static", StaticField->IsChecked() ? "yes" : "no");

if (VirtualField)
	wxConfigBase::Get()->Write("Astade/Virtual", VirtualField->IsChecked() ? "yes" : "no");

if (AbstractField)
	wxConfigBase::Get()->Write("Astade/Abstract", AbstractField->IsChecked() ? "yes" : "no");

if (traceLevel)
	wxConfigBase::Get()->Write("Astade/Tracelevel", traceLevel->GetValue());

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
	wxConfigBase::Get()->Write("Astade/Type", elementType);
}

wxConfigBase::Get()->Flush();

TouchAllParents();

Destroy();
