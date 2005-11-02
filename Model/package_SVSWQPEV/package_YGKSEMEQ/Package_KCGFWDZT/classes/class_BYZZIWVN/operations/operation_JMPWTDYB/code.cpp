SetMinSize(wxSize(430,350));
wxBoxSizer *topsizer = new wxBoxSizer( wxVERTICAL );
SetSizer( topsizer );

int elementType;

if (wxConfigBase::Get()->Read("Astade/Type",&elementType));
{
	switch(elementType&0x7ff00000)
	{
		case ITEM_IS_COMPONENTS:
		case ITEM_IS_COMPONENT:
		case ITEM_IS_CONFIGURATION:
		case ITEM_IS_PACKAGE:
			AddIconSizer(topsizer,true,false,false);
			AddDescriptionSizer(topsizer);
			NameEditField->SetValue(wxConfigBase::Get()->Read("Astade/Name",wxEmptyString));
			DescriptionEditField->SetValue(wxConfigBase::Get()->Read("Astade/Description",wxEmptyString));
		break;

		case ITEM_IS_CLASS:
			AddIconSizer(topsizer,true,false,false);
			AddBaseClassesSizer(topsizer);
			AddDescriptionSizer(topsizer);
			NameEditField->SetValue(wxConfigBase::Get()->Read("Astade/Name",wxEmptyString));
			AdditionalClassesEditField->SetValue(wxConfigBase::Get()->Read("Astade/AdditionalClasses",wxEmptyString));
			DescriptionEditField->SetValue(wxConfigBase::Get()->Read("Astade/Description",wxEmptyString));
		break;

		case ITEM_IS_OPERATION:
			if (elementType&ITEM_IS_NORMALOP)
			{
				AddIconSizer(topsizer,true,true,false);
				AddCheckboxSizer(topsizer,true,true,true,true,true);
				AddDescriptionSizer(topsizer);
				NameEditField->SetValue(wxConfigBase::Get()->Read("Astade/Name",wxEmptyString));
				TypeEditField->SetValue(wxConfigBase::Get()->Read("Astade/CodingType",wxEmptyString));
				DescriptionEditField->SetValue(wxConfigBase::Get()->Read("Astade/Description",wxEmptyString));
				ConstField->SetValue(wxConfigBase::Get()->Read("Astade/Const")=="yes");
				VirtualField->SetValue(wxConfigBase::Get()->Read("Astade/Virtual")=="yes");
				StaticField->SetValue(wxConfigBase::Get()->Read("Astade/Static")=="yes");
				AbstractField->SetValue(wxConfigBase::Get()->Read("Astade/Abstract")=="yes");
			}
			else
			if (elementType&ITEM_IS_DEST)
			{
				AddIconSizer(topsizer,false,false,false);
				AddCheckboxSizer(topsizer,false,true,false,false,true);
				AddDescriptionSizer(topsizer);
				DescriptionEditField->SetValue(wxConfigBase::Get()->Read("Astade/Description",wxEmptyString));
				VirtualField->SetValue(wxConfigBase::Get()->Read("Astade/Virtual")=="yes");
			}
			else
			{
				AddIconSizer(topsizer,false,false,false);
				AddCheckboxSizer(topsizer,false,false,false,false,true);
				AddInitializerSizer(topsizer);
				AddDescriptionSizer(topsizer);
				InitializerEditField->SetValue(wxConfigBase::Get()->Read("Astade/Initializer",wxEmptyString));
				DescriptionEditField->SetValue(wxConfigBase::Get()->Read("Astade/Description",wxEmptyString));
			}

			if (elementType&ITEM_IS_PRIVATE)
				m_private->SetValue(true);

			if (elementType&ITEM_IS_PROTECTED)
				m_protected->SetValue(true);

			if (elementType&ITEM_IS_PUBLIC)
				m_public->SetValue(true);

		break;

		case ITEM_IS_ATTRIBUTE:
			AddIconSizer(topsizer,true,true,true);
			AddCheckboxSizer(topsizer,true,false,true,false,true);
			AddDescriptionSizer(topsizer);
			NameEditField->SetValue(wxConfigBase::Get()->Read("Astade/Name",wxEmptyString));
			TypeEditField->SetValue(wxConfigBase::Get()->Read("Astade/CodingType",wxEmptyString));
			DescriptionEditField->SetValue(wxConfigBase::Get()->Read("Astade/Description",wxEmptyString));
			ConstField->SetValue(wxConfigBase::Get()->Read("Astade/Const")=="yes");
			StaticField->SetValue(wxConfigBase::Get()->Read("Astade/Static")=="yes");

			if (elementType&ITEM_IS_PRIVATE)
				m_private->SetValue(true);

			if (elementType&ITEM_IS_PROTECTED)
				m_protected->SetValue(true);

			if (elementType&ITEM_IS_PUBLIC)
				m_public->SetValue(true);

		break;

		default:
			AddIconSizer(topsizer,false,false,false);
			topsizer->AddStretchSpacer();
		break;
	}
	SetIcon();
}


AddButtonSizer(topsizer);

//AddBaseClassesSizer(topsizer);

/*
m_iType = 0;

myBitmap =  new wxStaticBitmap(this, ID_THEBITMAP, wxNullBitmap, wxPoint(9,0),wxSize(48,48) );

if ((file.size()>0) && (wxGetResource("Astade","Type",&m_iType,file)))
{
	new wxButton(this, ID_SAVEANDEXIT, "Save and Exit" , wxPoint(388,422),wxSize(100,32) );

	DefaultEditField = 0;
	switch (m_iType&0xfff00000)
	{
		case ITEM_IS_CLASS:         myBitmap->SetBitmap(wxIcon(Class));break;
		case ITEM_IS_COMPONENT:     myBitmap->SetBitmap(wxIcon(component));break;
		case ITEM_IS_COMPONENTS:    myBitmap->SetBitmap(wxIcon(components_xpm));break;
		case ITEM_IS_CONFIGURATION: myBitmap->SetBitmap(wxIcon(configuration_xpm));break;
		case ITEM_IS_PACKAGE:       myBitmap->SetBitmap(wxIcon(package));break;
		case ITEM_IS_TYPE:          myBitmap->SetBitmap(wxIcon(Type_xpm));break;
		case ITEM_IS_ATTRIBUTE:     myBitmap->SetBitmap(wxIcon(attribute));
			DefaultEditField =  new wxTextCtrl(this, ID_DEFAULTEDITFIELD, "" , wxPoint(100,84),wxSize(375,21) );
			DefaultEditField->SetMaxLength(128);
			(new wxStaticText(this, ID_NAME ,"default:" ,wxPoint(25,85)))->SetFont(wxFont(10, wxSWISS ,wxNORMAL,wxNORMAL,FALSE));
		break;
		case ITEM_IS_PARAMETER:     myBitmap->SetBitmap(wxIcon(parameter));break;
		case ITEM_IS_OPERATION:
			if (m_iType & ITEM_IS_NORMALOP)
				//Normal Operation
				myBitmap->SetBitmap(wxIcon(operation));
			else
			if (m_iType & ITEM_IS_DEST)
				//Destructor
				myBitmap->SetBitmap(wxIcon(dest_xpm));
			else
			//Constructor
			myBitmap->SetBitmap(wxIcon(Const));
		break;
	default: myBitmap->SetBitmap(wxIcon(edit));
	}
}
else
{
	myBitmap->SetBitmap(wxIcon(edit));
}

char* hp;

if ((file.size()>0) && (wxGetResource("Astade","PartnerPath",&hp,file)))
{
	wxFileName partnerName = wxString(hp);

	int i = partnerName.GetDirCount();
	partnerName.RemoveDir(i-1);
	partnerName.SetName("ModelNode");
	partnerName.SetExt("ini");
	wxString sName = "*deleted*";
	if (wxGetResource("Astade","Name", &hp, partnerName.GetFullPath()))
		RelatedClass = hp;
}

if ((file.size()>0) && (wxGetResource("Astade","Const",&hp,file)))
{
	m_oName = hp;
	ConstField =  new wxCheckBox(this, ID_CONST, "const" , wxPoint(25,58),wxSize(60,21) );
	ConstField->SetValue(m_oName=="yes");
}
else
	ConstField = NULL;

if (DefaultEditField)
{
	if ((file.size()>0) && (wxGetResource("Astade","Default",&hp,file)))
	{
		m_oName = hp;
		DefaultEditField->SetValue(Decode(m_oName));
	}
}

if ((file.size()>0) && (wxGetResource("Astade","Virtual",&hp,file)))
{
	m_oName = hp;
	VirtualField =  new wxCheckBox(this, ID_VIRTUAL, "virtual" , wxPoint(85,58),wxSize(60,21) );
	VirtualField->SetValue(m_oName=="yes");
}
else
	VirtualField = NULL;

if ((file.size()>0) && (wxGetResource("Astade","Static",&hp,file)))
{
	m_oName = hp;
	StaticField =  new wxCheckBox(this, ID_STATIC, "static" , wxPoint(145,58),wxSize(60,21) );
	StaticField->SetValue(m_oName=="yes");
}
else
	StaticField = NULL;

if ((file.size()>0) && (wxGetResource("Astade","Abstract",&hp,file)))
{
	m_oName = hp;
	AbstractField =  new wxCheckBox(this, ID_ABSTRACT, "abstract" , wxPoint(205,58),wxSize(60,21) );
	AbstractField->SetValue(m_oName=="yes");
}
else
	AbstractField = NULL;

if ((file.size()>0) && (wxGetResource("Astade","Name",&hp,file)))
{
	m_oName = hp;
	NameEditField =  new wxTextCtrl(this, ID_NAMEEDITFIELD, m_oName , wxPoint(100,12),wxSize(375,21) );
	NameEditField->SetMaxLength(128);
	if (((m_iType&0xfff00000)==ITEM_IS_OPERATION) && ((m_iType & ITEM_IS_NORMALOP)==0))
		NameEditField->SetEditable(false);
	(new wxStaticText(this, ID_NAME ,"name:" ,wxPoint(60,12)))->SetFont(wxFont(10, wxSWISS ,wxNORMAL,wxNORMAL,FALSE));
}
else
	NameEditField = NULL;

if ((file.size()>0) && (wxGetResource("Astade","CodingType",&hp,file)))
{
	wxString CodingType = hp;
	TypeEditField =  new wxTextCtrl(this, ID_NAMEEDITFIELD, Decode(CodingType) , wxPoint(100,33),wxSize(375,21) );
	TypeEditField->SetMaxLength(128);
	(new wxStaticText(this, ID_TYPE ,"type:" ,wxPoint(60,33)))->SetFont(wxFont(10, wxSWISS ,wxNORMAL,wxNORMAL,FALSE));
}
else
	TypeEditField = NULL;

if ((file.size()>0) && (wxGetResource("Astade","RelationType",&hp,file)))
{
	wxString CodingType = hp;

	wxString Multi;
	if (wxGetResource("Astade","Multiplicity",&hp,file))
		Multi = hp;
	else
		Multi = "1";

	wxArrayString arrayStringFor_WxComboBox1;
	arrayStringFor_WxComboBox1.Add("ImplementationDependency");
	arrayStringFor_WxComboBox1.Add("SpecificationDependency");
	arrayStringFor_WxComboBox1.Add("Association");
	arrayStringFor_WxComboBox1.Add("Agregation");
	arrayStringFor_WxComboBox1.Add("Composition");
	arrayStringFor_WxComboBox1.Add("Generalization");
	AgregationType =  new wxComboBox(this, ID_AGREGATIONTYPE ,CodingType ,wxPoint(25,58),wxSize(180,21), arrayStringFor_WxComboBox1, wxCB_READONLY   );

	if ((Multiplicity==NULL) &&
		((CodingType=="Association")||(CodingType=="Agregation")||(CodingType=="Composition")))
	{
		Multiplicity =  new wxComboBox(this, ID_AGREGATIONTYPE ,Multi ,wxPoint(330,58),wxSize(145,21),  getMultiplicityImplementations());
		TextMultiplicity = new wxStaticText(this, ID_TYPE ,"multiplicity:" ,wxPoint(260,58));
		TextMultiplicity->SetFont(wxFont(10, wxSWISS ,wxNORMAL,wxNORMAL,FALSE));

		hp[0]=0;
		wxGetResource("Astade","Implementation",&hp,file);
		Implementation =  new wxComboBox(this, ID_IMPLEMENTATION ,Decode(hp),wxPoint(105,100),wxSize(300,21), getRelationImplementations());
		TextImplementation = new wxStaticText(this, ID_TYPE ,"implement as:" ,wxPoint(25,100));
	}

	if (CodingType=="ImplementationDependency")
		myBitmap->SetBitmap(wxIcon(imprelation_xpm));

	if (CodingType=="SpecificationDependency")
		myBitmap->SetBitmap(wxIcon(specrelation_xpm));

	if (CodingType=="Association")
		myBitmap->SetBitmap(wxIcon(association));

	if (CodingType=="Agregation")
		myBitmap->SetBitmap(wxIcon(aggregation));

	if (CodingType=="Composition")
		myBitmap->SetBitmap(wxIcon(composition));

	if (CodingType=="Generalization")
		myBitmap->SetBitmap(wxIcon(generalisation));
}
else
	AgregationType = NULL;



if ((file.size()>0) && (wxGetResource("Astade","Declaration",&hp,file)))
{
	wxString Declaration = hp;
	DeclarationEditField =  new wxTextCtrl(this, ID_DECLARATIONEDITFIELD, Decode(Declaration) , wxPoint(25,78),wxSize(450,100), wxTE_MULTILINE );
	DeclarationEditField->SetMaxLength(0x4000);
	(new wxStaticText(this, ID_DESCRIPTION ,"declaration:" ,wxPoint(25,58)))->SetFont(wxFont(10, wxSWISS ,wxNORMAL,wxNORMAL,FALSE));
}

if ((m_iType&0xfff00000)==ITEM_IS_CLASS)
{
	wxString Declaration;
	if ((file.size()>0) && (wxGetResource("Astade","AdditionalClasses",&hp,file)))
	{
		Declaration = hp;
	}
	AdditionalClassesEditField =  new wxTextCtrl(this, ID_ADDITIONALCLASSESEDITFIELD, Decode(Declaration) , wxPoint(25,78),wxSize(450,100), wxTE_MULTILINE );
	AdditionalClassesEditField->SetMaxLength(0x4000);
	(new wxStaticText(this, ID_DESCRIPTION ,"Additional base classes:" ,wxPoint(25,58)))->SetFont(wxFont(10, wxSWISS ,wxNORMAL,wxNORMAL,FALSE));
}

if ((m_iType&0xfffff000)==ITEM_IS_OPERATION)
{
	wxString Declaration;
	if ((file.size()>0) && (wxGetResource("Astade","Initializer",&hp,file)))
	{
		Declaration = hp;
	}
	InitializerEditField =  new wxTextCtrl(this, ID_ADDITIONALCLASSESEDITFIELD, Decode(Declaration) , wxPoint(25,88),wxSize(450,90), wxTE_MULTILINE );
	InitializerEditField->SetMaxLength(0x4000);
	(new wxStaticText(this, ID_DESCRIPTION ,"Initializer:" ,wxPoint(25,68)))->SetFont(wxFont(10, wxSWISS ,wxNORMAL,wxNORMAL,FALSE));
}

if ((file.size()>0) && (wxGetResource("Astade","Description",&hp,file)))
{
	wxString Description = hp;
	DescriptionEditField =  new wxTextCtrl(this, ID_DESCRIPTIONEDITFIELD, Decode(Description) , wxPoint(25,200),wxSize(450,200), wxTE_MULTILINE );
	DescriptionEditField->SetMaxLength(0x4000);
	(new wxStaticText(this, ID_DESCRIPTION ,"description:" ,wxPoint(25,180)))->SetFont(wxFont(10, wxSWISS ,wxNORMAL,wxNORMAL,FALSE));
}
else
{
	DescriptionEditField =  new wxTextCtrl(this, ID_DESCRIPTIONEDITFIELD, "" , wxPoint(25,200),wxSize(450,200), wxTE_MULTILINE );
	DescriptionEditField->SetMaxLength(0x4000);
	(new wxStaticText(this, ID_DESCRIPTION ,"description:" ,wxPoint(25,180)))->SetFont(wxFont(10, wxSWISS ,wxNORMAL,wxNORMAL,FALSE));
}

if ((m_iType&ITEM_IS_PRIVATE)||
	(m_iType&ITEM_IS_PROTECTED)||
	(m_iType&ITEM_IS_PUBLIC))
{
	m_private =  new wxRadioButton(this, ID_M_PRIVATE ,"private" ,wxPoint(286,58),wxSize(70,21) );
	m_protected =  new wxRadioButton(this, ID_M_PROTECTED ,"protected" ,wxPoint(356,58),wxSize(70,21) );
	m_public =  new wxRadioButton(this, ID_M_PUBLIC ,"public",wxPoint(426,58),wxSize(70,21) );

	if (m_iType&ITEM_IS_PRIVATE)
	{
		m_private->SetValue(true);
		m_protected->SetValue(false);
		m_public->SetValue(false);
	}
	else
	if (m_iType&ITEM_IS_PROTECTED)
	{
		m_private->SetValue(false);
		m_protected->SetValue(true);
		m_public->SetValue(false);
	}
	else
	if (m_iType&ITEM_IS_PUBLIC)
	{
		m_private->SetValue(false);
		m_protected->SetValue(false);
		m_public->SetValue(true);
	}
}
else
{
	m_private = NULL;
	m_protected = NULL;
	m_public = NULL;
}

myBitmap->Enable(true);
*/