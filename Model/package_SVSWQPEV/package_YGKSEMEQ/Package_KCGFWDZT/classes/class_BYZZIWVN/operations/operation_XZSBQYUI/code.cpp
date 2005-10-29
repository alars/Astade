wxBoxSizer* box = new wxStaticBoxSizer( new wxStaticBox(this, -1, wxString("Additional base classes:")), wxHORIZONTAL );

AdditionalClassesEditField = new wxTextCtrl(this, ID_ADDITIONALCLASSESEDITFIELD, "" , wxDefaultPosition,wxDefaultSize, wxTE_MULTILINE );
AdditionalClassesEditField->SetMaxLength(0x4000);
box->Add(AdditionalClassesEditField,1,wxEXPAND);

topSizer->Add(box,1,wxEXPAND|wxALL,10);