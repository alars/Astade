wxBoxSizer* box = new wxStaticBoxSizer( new wxStaticBox(this, -1, wxString("Constraint:")), wxHORIZONTAL );

ConstraintEditField = new wxTextCtrl(this, ID_DESCRIPTIONEDITFIELD, "" , wxDefaultPosition,wxDefaultSize, wxTE_MULTILINE );
ConstraintEditField->SetMaxLength(0x4000);
box->Add(ConstraintEditField,1,wxEXPAND);

topSizer->Add(box,1,wxEXPAND|wxALL,10);

ConstraintEditField->SetValue(wxConfigBase::Get()->Read("Astade/Constraint",wxEmptyString));
