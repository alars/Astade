wxBoxSizer* box = new wxStaticBoxSizer( new wxStaticBox(this, -1, wxString("Declaration:")), wxHORIZONTAL );

DeclarationEditField = new wxTextCtrl(this, -1, "" , wxDefaultPosition,wxDefaultSize, wxTE_MULTILINE );
box->Add(DeclarationEditField,1,wxEXPAND);

topSizer->Add(box,1,wxEXPAND|wxALL,10);

DeclarationEditField->SetValue(wxConfigBase::Get()->Read("Astade/Declaration",wxEmptyString));
