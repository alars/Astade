wxBoxSizer* box = new wxStaticBoxSizer(new wxStaticBox(this, -1, wxString("Initializer:")), wxHORIZONTAL);

InitializerEditField = new wxTextCtrl(this, -1, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
InitializerEditField->SetMaxLength(0x4000);
box->Add(InitializerEditField, 1, wxEXPAND);

topSizer->Add(box, 1, wxEXPAND|wxALL, 10);

InitializerEditField->SetValue(wxConfigBase::Get()->Read("Astade/Initializer", wxEmptyString));
