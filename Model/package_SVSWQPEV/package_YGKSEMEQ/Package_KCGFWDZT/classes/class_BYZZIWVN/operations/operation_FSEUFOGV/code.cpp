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
		case ITEM_IS_STATECHART:    myBitmap->SetBitmap(wxIcon(Statechart_xpm));break;
		case ITEM_IS_STATE:		    	myBitmap->SetBitmap(wxIcon(State_xpm));break;

		case ITEM_IS_CLASS:
		{
			bool is = false;
			wxConfigBase::Get()->Read("Astade/LibClass",&is);
			if (is)
			    myBitmap->SetBitmap(wxIcon(libClass_xpm));
			else
			    myBitmap->SetBitmap(wxIcon(Class));
		}
		break;

		case ITEM_IS_OPERATION:
			if ((elementType&ITEM_IS_NORMALOP) && m_private)
			{
				if (m_private->GetValue())
					myBitmap->SetBitmap(wxIcon(privop));
				else
				if (m_protected->GetValue())
					myBitmap->SetBitmap(wxIcon(protop));
				else
					myBitmap->SetBitmap(wxIcon(operation));
			}
			else
			if ((elementType&ITEM_IS_DEST) && m_private)
			{
				if (m_private->GetValue())
					myBitmap->SetBitmap(wxIcon(privdest_xpm));
				else
				if (m_protected->GetValue())
					myBitmap->SetBitmap(wxIcon(protdest_xpm));
				else
					myBitmap->SetBitmap(wxIcon(dest_xpm));
			}
			else
			if (m_private)
			{
				if (m_private->GetValue())
					myBitmap->SetBitmap(wxIcon(privconst));
				else
				if (m_protected->GetValue())
					myBitmap->SetBitmap(wxIcon(protconst));
				else
					myBitmap->SetBitmap(wxIcon(Const));
			}
		break;

		case ITEM_IS_ATTRIBUTE:
			if (m_private->GetValue())
				myBitmap->SetBitmap(wxIcon(privAttr));
			else
			if (m_protected->GetValue())
				myBitmap->SetBitmap(wxIcon(protAttr));
			else
				myBitmap->SetBitmap(wxIcon(attribute));
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
