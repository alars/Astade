//~~ void AddCheckboxSizer(wxSizer* topSizer, wxWindow* parent, bool hasConst, bool hasVirtual, bool hasStatic, bool hasAbstract, bool hasVisibility, bool hasInline, bool hasExplicit, bool hasIn = false, bool hasOut = false, bool hasDelegate = false) [ResourceEdit] ~~
/* vi: set tabstop=4: */

wxBoxSizer *checkbox = new wxBoxSizer(wxHORIZONTAL);
topSizer->Add(checkbox, 0, wxEXPAND|wxALL, 10);

if (hasInline)
{
	InlineField = new wxCheckBox(parent, ID_INLINE, wxS("inline"));
	checkbox->Add(InlineField, 0);
	InlineField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Inline")) == wxS("yes"));
	checkbox->AddStretchSpacer();
}

if (hasIn)
{
	inField = new wxCheckBox(parent, ID_IN, wxS("input"));
	checkbox->Add(inField, 0);
	inField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/InputParameter")) == wxS("yes"));
	checkbox->AddStretchSpacer();
}

if (hasOut)
{
	outField = new wxCheckBox(parent, ID_OUT, wxS("output"));
	checkbox->Add(outField, 0);
	outField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/OutputParameter")) == wxS("yes"));
	checkbox->AddStretchSpacer();
}

if (hasDelegate)
{
	delegateField = new wxCheckBox(parent, ID_OUT, wxS("delegate"));
	checkbox->Add(delegateField, 0);
	delegateField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/delegate")) == wxS("yes"));
	checkbox->AddStretchSpacer();
}

if (hasConst)
{
	ConstField = new wxCheckBox(parent, ID_CONST, wxS("const"));
	checkbox->Add(ConstField, 0);
	ConstField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Const")) == wxS("yes"));
}
else if (hasExplicit)
{
	ExplicitField = new wxCheckBox(parent, ID_EXPLICIT, wxS("explicit"));
	checkbox->Add(ExplicitField, 0);
	ExplicitField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Explicit")) == wxS("yes"));
}

checkbox->AddStretchSpacer();

if (hasStatic)
{
	StaticField = new wxCheckBox(parent, ID_STATIC, wxS("static"));
	checkbox->Add(StaticField, 0);
	StaticField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Static")) == wxS("yes"));
}

checkbox->AddStretchSpacer();

if (hasVirtual)
{
	VirtualField = new wxCheckBox(parent, ID_VIRTUAL, wxS("virtual"));
	checkbox->Add(VirtualField, 0);
	VirtualField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Virtual")) == wxS("yes"));
}

checkbox->AddStretchSpacer();

if (hasAbstract)
{
	AbstractField = new wxCheckBox(parent, ID_ABSTRACT, wxS("abstract"));
	checkbox->Add(AbstractField, 0);
	AbstractField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Abstract")) == wxS("yes"));
}

if (hasVisibility)
{
	// the dummy Button is needed, because otherwise the Radiobuttons are not properly initialized for constructors
	// I dont't know why !!!!!
	if (!hasVirtual && !hasStatic && !hasAbstract)
	{
		wxRadioButton* dummy = new wxRadioButton(parent, -1, wxS("dummy"), wxPoint(2000, 2000), wxDefaultSize, wxRB_GROUP );
		dummy = dummy;
	}
	m_private = new wxRadioButton(parent, ID_M_PRIVATE, wxS("private"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	m_protected = new wxRadioButton(parent, ID_M_PROTECTED, wxS("protected"));
	m_public = new wxRadioButton(parent, ID_M_PUBLIC, wxS("public"));

	checkbox->AddStretchSpacer();

	checkbox->Add(m_private, 0);
	checkbox->AddStretchSpacer();
	checkbox->Add(m_protected, 0);
	checkbox->AddStretchSpacer();
	checkbox->Add(m_public, 0);

	int elementType;

	wxConfigBase::Get()->Read(wxS("Astade/Type"), &elementType);

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
