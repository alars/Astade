//~~ void SetIcon() [ResourceEdit] ~~
int elementType;

if (wxConfigBase::Get()->Read("Astade/Type",&elementType));
{
	switch(elementType & ITEM_TYPE_MASK)
	{
		case ITEM_IS_COMPONENT:     myBitmap->SetBitmap(EditIcons::GetComponentIcon());break;
		case ITEM_IS_COMPONENTS:    myBitmap->SetBitmap(EditIcons::GetComponentsIcon());break;
		case ITEM_IS_CONFIGURATION: myBitmap->SetBitmap(EditIcons::GetConfigurationIcon());break;
		case ITEM_IS_PACKAGE:       myBitmap->SetBitmap(EditIcons::GetPackageIcon(isNamespace->IsChecked()));break;
		case ITEM_IS_TYPE:          myBitmap->SetBitmap(EditIcons::GetTypeIcon());break;
		case ITEM_IS_STATECHART:    myBitmap->SetBitmap(EditIcons::GetStatechartIcon());break;
		case ITEM_IS_STATE:		   	myBitmap->SetBitmap(EditIcons::GetStateIcon());break;
		case ITEM_IS_PARAMETER:		myBitmap->SetBitmap(EditIcons::GetParameterIcon(inField->IsChecked(), outField->IsChecked()));break;

		case ITEM_IS_CLASS:
		{
			bool is = false;

			wxConfigBase::Get()->Read("Astade/LibClass",&is);
			if (is)
			    myBitmap->SetBitmap(EditIcons::GetLibclassIcon());
			else
			{
				wxConfigBase::Get()->Read("Astade/ManualClass",&is);
				if (is)
					myBitmap->SetBitmap(EditIcons::GetManualclassIcon());
				else
					myBitmap->SetBitmap(EditIcons::GetClassIcon(codingLanguage->GetValue()));
			}
		}
		break;

		case ITEM_IS_OPERATION:
		{
			int operationType = 2;
			if ((elementType&ITEM_IS_DEST) && m_private)
				operationType = 1;
			else
			if ((elementType&ITEM_IS_NORMALOP) && m_private)
				operationType = 0;

			int visibility = 0;
			if (m_protected->GetValue())
				visibility = 1;
			else if (m_private->GetValue())
				visibility = 2;

			int scope = 0;
			if (StaticField && StaticField->IsChecked())
				scope = 1;
			if (VirtualField && VirtualField->IsChecked())
				scope = 2;
			if (AbstractField && AbstractField->IsChecked())
				scope = 3;

			bool isConst = false;
			if (ConstField && ConstField->IsChecked())
				isConst = true;

			bool isInline = false;
			if (InlineField && InlineField->IsChecked())
				isInline = true;

			myBitmap->SetBitmap(EditIcons::GetOperationIcon(operationType, visibility, scope, isConst, isInline));
		}
		break;

		case ITEM_IS_ATTRIBUTE:
		{
			int visibility = 0;
			if (m_protected->GetValue())
				visibility = 1;
			else if (m_private->GetValue())
				visibility = 2;

			int scope = 0;
			if (StaticField && StaticField->IsChecked())
				scope = 1;

			bool isConst = false;
			if (ConstField && ConstField->IsChecked())
				isConst = true;

			myBitmap->SetBitmap(EditIcons::GetAttributeIcon(visibility, scope, isConst));
		}
		break;

		case ITEM_IS_RELATION:
			if (AggregationType->GetValue()=="ImplementationDependency")
			{
				myBitmap->SetBitmap(EditIcons::GetImplementationDependencyIcon());
				NameEditField->Hide();
				nameText->Hide();
				Multiplicity->Hide();
				multiplicityText->Hide();
				Implementation->Hide();
				implementationText->Hide();
				DefaultEditField->Hide();
				defaultText->Hide();
				StaticField->Hide();
				templateField->Hide();
				typeText->Hide();
			}

			if (AggregationType->GetValue()=="SpecificationDependency")
			{
				myBitmap->SetBitmap(EditIcons::GetSpecificationDependencyIcon());
				NameEditField->Hide();
				nameText->Hide();
				Multiplicity->Hide();
				multiplicityText->Hide();
				Implementation->Hide();
				implementationText->Hide();
				DefaultEditField->Hide();
				defaultText->Hide();
				StaticField->Hide();
				templateField->Hide();
				typeText->Hide();
			}

			if (AggregationType->GetValue()=="Friend")
			{
				myBitmap->SetBitmap(EditIcons::GetFriendIcon());
				NameEditField->Hide();
				nameText->Hide();
				Multiplicity->Hide();
				multiplicityText->Hide();
				Implementation->Hide();
				implementationText->Hide();
				DefaultEditField->Hide();
				defaultText->Hide();
				StaticField->Hide();
				templateField->Hide();
				typeText->Hide();
			}

			if (AggregationType->GetValue()=="Association")
			{
				myBitmap->SetBitmap(EditIcons::GetAssociationIcon());
				NameEditField->Show();
				nameText->Show();
				Multiplicity->Show();
				multiplicityText->Show();
				Implementation->Show();
				implementationText->Show();
				DefaultEditField->Show();
				defaultText->Show();
				StaticField->Show();
				templateField->Hide();
				typeText->Hide();
			}

			if (AggregationType->GetValue()=="Aggregation")
			{
				myBitmap->SetBitmap(EditIcons::GetAggregationIcon());
				NameEditField->Show();
				nameText->Show();
				Multiplicity->Show();
				multiplicityText->Show();
				Implementation->Show();
				implementationText->Show();
				DefaultEditField->Show();
				defaultText->Show();
				StaticField->Show();
				templateField->Hide();
				typeText->Hide();
			}

			if (AggregationType->GetValue()=="Composition")
			{
				myBitmap->SetBitmap(EditIcons::GetCompositionIcon());
				NameEditField->Show();
				nameText->Show();
				Multiplicity->Show();
				multiplicityText->Show();
				Implementation->Show();
				implementationText->Show();
				DefaultEditField->Show();
				defaultText->Show();
				StaticField->Show();
				templateField->Hide();
				typeText->Hide();
			}

			if (AggregationType->GetValue()=="Generalization")
			{
				myBitmap->SetBitmap(EditIcons::GetGeneralisationIcon());
				NameEditField->Hide();
				nameText->Hide();
				Multiplicity->Hide();
				multiplicityText->Hide();
				Implementation->Hide();
				implementationText->Hide();
				DefaultEditField->Hide();
				defaultText->Hide();
				StaticField->Hide();
				templateField->Show();
				typeText->Show();
			}
		break;

		case ITEM_IS_TRANSITION:
			if (transitionType->GetValue()=="Self")
			{
				myBitmap->SetBitmap(EditIcons::GetSelftransitionIcon());
				destinationText->Hide();
				destinationEditField->Hide();
			}
			else
			if (transitionType->GetValue()=="Internal")
			{
				myBitmap->SetBitmap(EditIcons::GetInternaltransitionIcon());
				destinationText->Hide();
				destinationEditField->Hide();
			}
			else
			{
				myBitmap->SetBitmap(EditIcons::GetTransitionIcon());
				destinationText->Show();
				destinationEditField->Show();
			}
		break;

	}
	Layout();
}
