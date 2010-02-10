/* vi: set tabstop=4: */

wxBoxSizer *checkbox = new wxBoxSizer(wxHORIZONTAL);
topSizer->Add(checkbox, 0, wxEXPAND|wxALL, 10);

if (hasInline)
{
	InlineField = new wxCheckBox(this, ID_INLINE, "inline");
	checkbox->Add(InlineField, 0);
	InlineField->SetValue(wxConfigBase::Get()->Read("Astade/Inline") == "yes");
	checkbox->AddStretchSpacer();
}

if (hasIn)
{
	inField = new wxCheckBox(this, ID_IN, "input");
	checkbox->Add(inField, 0);
	inField->SetValue(wxConfigBase::Get()->Read("Astade/InputParameter") == "yes");
	checkbox->AddStretchSpacer();
}

if (hasOut)
{
	outField = new wxCheckBox(this, ID_OUT, "output");
	checkbox->Add(outField, 0);
	outField->SetValue(wxConfigBase::Get()->Read("Astade/OutputParameter") == "yes");
	checkbox->AddStretchSpacer();
}

if (hasConst)
{
	ConstField = new wxCheckBox(this, ID_CONST, "const");
	checkbox->Add(ConstField, 0);
	ConstField->SetValue(wxConfigBase::Get()->Read("Astade/Const") == "yes");
}
else if (hasExplicit)
{
	ExplicitField = new wxCheckBox(this, ID_EXPLICIT, "explicit");
	checkbox->Add(ExplicitField, 0);
	ExplicitField->SetValue(wxConfigBase::Get()->Read("Astade/Explicit") == "yes");
}

checkbox->AddStretchSpacer();

if (hasStatic)
{
	StaticField = new wxCheckBox(this, ID_STATIC, "static");
	checkbox->Add(StaticField, 0);
	StaticField->SetValue(wxConfigBase::Get()->Read("Astade/Static") == "yes");
}

checkbox->AddStretchSpacer();

if (hasVirtual)
{
	VirtualField = new wxCheckBox(this, ID_VIRTUAL, "virtual");
	checkbox->Add(VirtualField, 0);
	VirtualField->SetValue(wxConfigBase::Get()->Read("Astade/Virtual") == "yes");
}

checkbox->AddStretchSpacer();

if (hasAbstract)
{
	AbstractField = new wxCheckBox(this, ID_ABSTRACT, "abstract");
	checkbox->Add(AbstractField, 0);
	AbstractField->SetValue(wxConfigBase::Get()->Read("Astade/Abstract") == "yes");
}

if (hasVisibility)
{
	// the dummy Button is needed, because otherwise the Radiobuttons are not properly initialized for constructors
	// I dont't know why !!!!!
	if (!hasVirtual && !hasStatic && !hasAbstract)
	{
		wxRadioButton* dummy = new wxRadioButton(this, -1 ,"dummy", wxPoint(2000, 2000), wxDefaultSize, wxRB_GROUP );
		dummy = dummy;
	}
	m_private = new wxRadioButton(this, ID_M_PRIVATE, "private", wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	m_protected = new wxRadioButton(this, ID_M_PROTECTED, "protected");
	m_public = new wxRadioButton(this, ID_M_PUBLIC, "public");

	checkbox->AddStretchSpacer();

	checkbox->Add(m_private, 0);
	checkbox->AddStretchSpacer();
	checkbox->Add(m_protected, 0);
	checkbox->AddStretchSpacer();
	checkbox->Add(m_public, 0);

	int elementType;

	wxConfigBase::Get()->Read("Astade/Type", &elementType);

	if (elementType & ITEM_IS_PRIVATE)
		m_private->SetValue(true);

	if (elementType & ITEM_IS_PROTECTED)
		m_protected->SetValue(true);

	if (elementType & ITEM_IS_PUBLIC)
		m_public->SetValue(true);
}
else
{
	checkbox->AddStretchSpacer();
	checkbox->AddStretchSpacer();
}
