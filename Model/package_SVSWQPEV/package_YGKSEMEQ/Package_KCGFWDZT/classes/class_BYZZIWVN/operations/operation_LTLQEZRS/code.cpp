wxBoxSizer* box = new wxStaticBoxSizer( new wxStaticBox(this, -1, wxString("Description:")), wxHORIZONTAL );

DescriptionEditField = new wxTextCtrl(this, ID_DESCRIPTIONEDITFIELD, "" , wxDefaultPosition,wxDefaultSize, wxTE_MULTILINE );
DescriptionEditField->SetMaxLength(0x4000);
box->Add(DescriptionEditField,1,wxEXPAND);

topSizer->Add(box,3,wxEXPAND|wxALL,10);

DescriptionEditField->SetValue(wxConfigBase::Get()->Read("Astade/Description",wxEmptyString));