wxBoxSizer* box = new wxStaticBoxSizer( new wxStaticBox(this, -1, wxString("Return value description:")), wxHORIZONTAL );

ReturnDescriptionEditField = new wxTextCtrl(this, ID_RETURNDESCRIPTIONEDITFIELD, "" , wxDefaultPosition,wxDefaultSize, wxTE_MULTILINE );
box->Add(ReturnDescriptionEditField,1,wxEXPAND);

topSizer->Add(box,1,wxEXPAND|wxALL,10);

ReturnDescriptionEditField->SetValue(wxConfigBase::Get()->Read("Astade/ReturnDescription",wxEmptyString));
