int elementType;

if (wxConfigBase::Get()->Read("Astade/Type",&elementType));
{
	switch(elementType&0x7ff00000)
	{
		case ITEM_IS_CLASS:         myBitmap->SetBitmap(wxIcon(Class));break;
		case ITEM_IS_COMPONENT:     myBitmap->SetBitmap(wxIcon(component));break;
		case ITEM_IS_COMPONENTS:    myBitmap->SetBitmap(wxIcon(components_xpm));break;
		case ITEM_IS_CONFIGURATION: myBitmap->SetBitmap(wxIcon(configuration_xpm));break;
		case ITEM_IS_PACKAGE:       myBitmap->SetBitmap(wxIcon(package));break;
		case ITEM_IS_TYPE:          myBitmap->SetBitmap(wxIcon(Type_xpm));break;
		case ITEM_IS_STATECHART:    myBitmap->SetBitmap(wxIcon(Statechart_xpm));break;

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
			if (AgregationType->GetValue()=="ImplementationDependency")
			{
				myBitmap->SetBitmap(wxIcon(imprelation_xpm));
				NameEditField->Hide();
				nameText->Hide();
				Multiplicity->Hide();
				multiplicityText->Hide();
				Implementation->Hide();
				implementationText->Hide();
			}

			if (AgregationType->GetValue()=="SpecificationDependency")
			{
				myBitmap->SetBitmap(wxIcon(specrelation_xpm));
				NameEditField->Hide();
				nameText->Hide();
				Multiplicity->Hide();
				multiplicityText->Hide();
				Implementation->Hide();
				implementationText->Hide();
			}

			if (AgregationType->GetValue()=="Association")
			{
				myBitmap->SetBitmap(wxIcon(association));
				NameEditField->Show();
				nameText->Show();
				Multiplicity->Show();
				multiplicityText->Show();
				Implementation->Show();
				implementationText->Show();
			}

			if (AgregationType->GetValue()=="Agregation")
			{
				myBitmap->SetBitmap(wxIcon(aggregation));
				NameEditField->Show();
				nameText->Show();
				Multiplicity->Show();
				multiplicityText->Show();
				Implementation->Show();
				implementationText->Show();
			}

			if (AgregationType->GetValue()=="Composition")
			{
				myBitmap->SetBitmap(wxIcon(composition));
				NameEditField->Show();
				nameText->Show();
				Multiplicity->Show();
				multiplicityText->Show();
				Implementation->Show();
				implementationText->Show();
			}

			if (AgregationType->GetValue()=="Generalization")
			{
				myBitmap->SetBitmap(wxIcon(generalisation));
				NameEditField->Hide();
				nameText->Hide();
				Multiplicity->Hide();
				multiplicityText->Hide();
				Implementation->Hide();
				implementationText->Hide();
			}
		break;

		case ITEM_IS_PARAMETER:
			myBitmap->SetBitmap(wxIcon(parameter));
		break;

	}
}
