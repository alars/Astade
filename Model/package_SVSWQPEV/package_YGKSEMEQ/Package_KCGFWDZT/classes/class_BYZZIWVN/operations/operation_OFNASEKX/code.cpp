wxBoxSizer* box = new wxStaticBoxSizer( new wxStaticBox(this, -1, wxString("Return value description:")), wxHORIZONTAL );

ReturnDescriptionEditField = new wxTextCtrl(this, ID_RETURNDESCRIPTIONEDITFIELD, "" , wxDefaultPosition,wxDefaultSize, wxTE_MULTILINE );
ReturnDescriptionEditField->SetMaxLength(0x4000);
box->Add(ReturnDescriptionEditField,1,wxEXPAND);

topSizer->Add(box,3,wxEXPAND|wxALL,10);

ReturnDescriptionEditField->SetValue(wxConfigBase::Get()->Read("Astade/ReturnDescription",wxEmptyString));