wxBoxSizer *icon_sizer = new wxBoxSizer( wxHORIZONTAL );
topSizer->Add(icon_sizer,0,wxEXPAND|wxALL|wxALIGN_TOP,10);

myBitmap =  new wxStaticBitmap(this, ID_THEBITMAP, wxNullBitmap, wxPoint(9,0),wxSize(48,48) );
myBitmap -> SetBitmap(wxIcon(edit));

icon_sizer->Add(myBitmap,0,wxALIGN_LEFT);

wxBoxSizer *name_type_sizer = new wxBoxSizer( wxVERTICAL );
icon_sizer->Add(name_type_sizer,1,wxEXPAND);

wxBoxSizer *name_sizer = new wxBoxSizer( wxHORIZONTAL );
name_type_sizer->Add(name_sizer,1,wxEXPAND);

wxBoxSizer *type_sizer = new wxBoxSizer( wxHORIZONTAL );
name_type_sizer->Add(type_sizer,1,wxEXPAND);

if (namefield)
{
	nameText = 	new wxStaticText(this, -1 ,"name:",wxDefaultPosition,wxSize(35,15));
	name_sizer->Add(nameText,0,wxALIGN_LEFT | wxLEFT,10);

	NameEditField =  new wxTextCtrl(this, -1);
	NameEditField->SetMaxLength(128);

	name_sizer->Add(NameEditField,1,wxLEFT,10);

	NameEditField->SetValue(wxConfigBase::Get()->Read("Astade/Name",wxEmptyString));
}

if (typefield)
{
	type_sizer->Add(
		new wxStaticText(this, -1 ,"type:",wxDefaultPosition,wxSize(35,15)),0,wxALIGN_LEFT | wxLEFT,10);

	TypeEditField =  new wxTextCtrl(this, -1);
	TypeEditField->SetMaxLength(256);

	type_sizer->Add(TypeEditField,1,wxLEFT,10);

	TypeEditField->SetValue(wxConfigBase::Get()->Read("Astade/CodingType",wxEmptyString));
}

if (defaultfield)
{
	wxBoxSizer *default_sizer = new wxBoxSizer( wxHORIZONTAL );
	name_type_sizer->Add(default_sizer,1,wxEXPAND);

	default_sizer->Add(
		new wxStaticText(this, -1 ,"default:",wxDefaultPosition,wxSize(35,15)),0,wxALIGN_LEFT | wxLEFT,10);

	DefaultEditField =  new wxTextCtrl(this, -1);
	DefaultEditField->SetMaxLength(256);

	default_sizer->Add(DefaultEditField,1,wxLEFT,10);

	DefaultEditField->SetValue(wxConfigBase::Get()->Read("Astade/Default",wxEmptyString));
}