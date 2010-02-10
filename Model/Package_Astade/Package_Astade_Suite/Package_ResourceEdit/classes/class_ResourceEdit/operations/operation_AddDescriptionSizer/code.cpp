wxBoxSizer* box = new wxStaticBoxSizer( new wxStaticBox(this, -1, wxString("Description:")), wxHORIZONTAL );

DescriptionEditField = new wxTextCtrl(this, ID_DESCRIPTIONEDITFIELD, "" , wxDefaultPosition,wxDefaultSize, wxTE_MULTILINE );
box->Add(DescriptionEditField,1,wxEXPAND);

topSizer->Add(box,1,wxEXPAND|wxALL,10);

DescriptionEditField->SetValue(wxConfigBase::Get()->Read("Astade/Description",wxEmptyString));