//~~ void AddIconSizer(wxSizer* topSizer, bool namefield, bool typefield, bool defaultfield, bool timeoutfield, bool templatefield, bool bitsfield = false) [ResourceEdit] ~~
/* vi: set tabstop=4: */

wxBoxSizer *icon_sizer = new wxBoxSizer(wxHORIZONTAL);
topSizer->Add(icon_sizer, 0, wxEXPAND|wxALL|wxALIGN_TOP, 10);

myBitmap = new wxStaticBitmap(this, ID_THEBITMAP, wxNullBitmap);

icon_sizer->Add(myBitmap, 0, wxALIGN_LEFT);

wxBoxSizer *name_type_sizer = new wxBoxSizer(wxVERTICAL);
icon_sizer->Add(name_type_sizer, 1, wxEXPAND);

wxBoxSizer *name_sizer = new wxBoxSizer(wxHORIZONTAL);
name_type_sizer->Add(name_sizer, 1, wxEXPAND);

wxBoxSizer *type_sizer = new wxBoxSizer(wxHORIZONTAL);
name_type_sizer->Add(type_sizer, 1, wxEXPAND);

if (namefield)
{
	nameText = new wxStaticText(this, -1, wxS("name:"), wxDefaultPosition, wxSize(60,15));
	name_sizer->Add(nameText, 0, wxALIGN_LEFT|wxLEFT, 10);

	NameEditField = new wxTextCtrl(this, -1);
	NameEditField->SetMaxLength(512);

	name_sizer->Add(NameEditField, 1, wxLEFT, 10);

	NameEditField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Name"), wxEmptyString));
}

if (typefield)
{
	typeText = new wxStaticText(this, -1, wxS("type:"), wxDefaultPosition, wxSize(60,15));
	type_sizer->Add(typeText, 0, wxALIGN_LEFT|wxLEFT, 10);

	TypeEditField = new wxTextCtrl(this, -1);
	TypeEditField->SetMaxLength(512);

	type_sizer->Add(TypeEditField, 1, wxLEFT, 10);

	TypeEditField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/CodingType"), wxEmptyString));
}

if (bitsfield)
{
	bitsText = new wxStaticText(this, -1, wxS("Bits:"), wxDefaultPosition, wxSize(60,15));
	type_sizer->Add(bitsText, 0, wxALIGN_LEFT|wxLEFT, 10);

	bitsEditField = new wxTextCtrl(this, -1);
	bitsEditField->SetMaxLength(128);

	type_sizer->Add(bitsEditField, 1, wxLEFT, 10);

	bitsEditField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Bits"), wxEmptyString));
}

if (timeoutfield)
{
	typeText = new wxStaticText(this, -1, wxS("timeout:"), wxDefaultPosition, wxSize(60,15));
	type_sizer->Add(typeText, 0, wxALIGN_LEFT|wxLEFT, 10);

	timeoutField = new wxTextCtrl(this, -1, wxEmptyString);

	type_sizer->Add(timeoutField, 1, wxLEFT, 10);

	timeoutField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Timeout"), wxEmptyString));
}

if (templatefield)
{
	typeText = new wxStaticText(this, -1, wxS("template:"), wxDefaultPosition, wxSize(60,15));
	type_sizer->Add(typeText, 0, wxALIGN_LEFT|wxLEFT, 10);

	templateField = new wxTextCtrl(this, -1, wxEmptyString);

	type_sizer->Add(templateField, 1, wxLEFT, 10);

	templateField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Template"), wxEmptyString));
}

if (defaultfield)
{
	wxBoxSizer *default_sizer = new wxBoxSizer(wxHORIZONTAL);
	name_type_sizer->Add(default_sizer, 1, wxEXPAND);

	defaultText = new wxStaticText(this, -1, wxS("default:"), wxDefaultPosition, wxSize(60,15));
	default_sizer->Add(defaultText, 0, wxALIGN_LEFT|wxLEFT, 10);

	DefaultEditField = new wxTextCtrl(this, -1);
	DefaultEditField->SetMaxLength(256);

	default_sizer->Add(DefaultEditField, 1, wxLEFT, 10);

	DefaultEditField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Default"), wxEmptyString));
}
