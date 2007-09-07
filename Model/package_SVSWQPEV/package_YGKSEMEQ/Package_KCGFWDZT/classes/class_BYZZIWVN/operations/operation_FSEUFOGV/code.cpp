int elementType;

if (wxConfigBase::Get()->Read("Astade/Type",&elementType));
{
	switch(elementType & ITEM_TYPE_MASK)
	{
		case ITEM_IS_COMPONENT:     myBitmap->SetBitmap(EditIcons::GetComponentIcon());break;
		case ITEM_IS_COMPONENTS:    myBitmap->SetBitmap(EditIcons::GetComponentsIcon());break;
		case ITEM_IS_CONFIGURATION: myBitmap->SetBitmap(EditIcons::GetConfigurationIcon());break;
		case ITEM_IS_PACKAGE:       myBitmap->SetBitmap(EditIcons::GetPackageIcon());break;
		case ITEM_IS_TYPE:          myBitmap->SetBitmap(EditIcons::GetTypeIcon());break;
		case ITEM_IS_STATECHART:    myBitmap->SetBitmap(EditIcons::GetStatechartIcon());break;
		case ITEM_IS_STATE:		   	myBitmap->SetBitmap(EditIcons::GetStateIcon());break;

		case ITEM_IS_CLASS:
		{
			bool is = false;
			wxConfigBase::Get()->Read("Astade/LibClass",&is);
			if (is)
			    myBitmap->SetBitmap(EditIcons::GetLibclassIcon());
			else
			    myBitmap->SetBitmap(EditIcons::GetClassIcon());
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

			myBitmap->SetBitmap(EditIcons::GetOperationIcon(operationType, visibility, scope, isConst));
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
				myBitmap->SetBitmap(wxIcon(imprelation_xpm));
				NameEditField->Hide();
				nameText->Hide();
				Multiplicity->Hide();
				multiplicityText->Hide();
				Implementation->Hide();
				implementationText->Hide();
				DefaultEditField->Hide();
				defaultText->Hide();
				StaticField->Hide();
			}

			if (AggregationType->GetValue()=="SpecificationDependency")
			{
				myBitmap->SetBitmap(wxIcon(specrelation_xpm));
				NameEditField->Hide();
				nameText->Hide();
				Multiplicity->Hide();
				multiplicityText->Hide();
				Implementation->Hide();
				implementationText->Hide();
				DefaultEditField->Hide();
				defaultText->Hide();
				StaticField->Hide();
			}

			if (AggregationType->GetValue()=="Friend")
			{
				myBitmap->SetBitmap(wxIcon(friend_xpm));
				NameEditField->Hide();
				nameText->Hide();
				Multiplicity->Hide();
				multiplicityText->Hide();
				Implementation->Hide();
				implementationText->Hide();
				DefaultEditField->Hide();
				defaultText->Hide();
				StaticField->Hide();
			}

			if (AggregationType->GetValue()=="Association")
			{
				myBitmap->SetBitmap(wxIcon(association));
				NameEditField->Show();
				nameText->Show();
				Multiplicity->Show();
				multiplicityText->Show();
				Implementation->Show();
				implementationText->Show();
				DefaultEditField->Show();
				defaultText->Show();
				StaticField->Show();
			}

			if (AggregationType->GetValue()=="Aggregation")
			{
				myBitmap->SetBitmap(wxIcon(aggregation));
				NameEditField->Show();
				nameText->Show();
				Multiplicity->Show();
				multiplicityText->Show();
				Implementation->Show();
				implementationText->Show();
				DefaultEditField->Show();
				defaultText->Show();
				StaticField->Show();
			}

			if (AggregationType->GetValue()=="Composition")
			{
				myBitmap->SetBitmap(wxIcon(composition));
				NameEditField->Show();
				nameText->Show();
				Multiplicity->Show();
				multiplicityText->Show();
				Implementation->Show();
				implementationText->Show();
				DefaultEditField->Show();
				defaultText->Show();
				StaticField->Show();
			}

			if (AggregationType->GetValue()=="Generalization")
			{
				myBitmap->SetBitmap(wxIcon(generalisation));
				NameEditField->Hide();
				nameText->Hide();
				Multiplicity->Hide();
				multiplicityText->Hide();
				Implementation->Hide();
				implementationText->Hide();
				DefaultEditField->Hide();
				defaultText->Hide();
				StaticField->Hide();
			}
		break;

		case ITEM_IS_PARAMETER:
			myBitmap->SetBitmap(wxIcon(parameter));
		break;

		case ITEM_IS_TRANSITION:
			if (transitionType->GetValue()=="Self")
			{
				myBitmap->SetBitmap(wxIcon(SelfTransition_xpm));
				destinationText->Hide();
				destinationEditField->Hide();
			}
			else
			if (transitionType->GetValue()=="Internal")
			{
				myBitmap->SetBitmap(wxIcon(InternalTransition_xpm));
				destinationText->Hide();
				destinationEditField->Hide();
			}
			else
			{
				myBitmap->SetBitmap(wxIcon(Transition_xpm));
				destinationText->Show();
				destinationEditField->Show();
			}
		break;

	}
	Layout();
}
