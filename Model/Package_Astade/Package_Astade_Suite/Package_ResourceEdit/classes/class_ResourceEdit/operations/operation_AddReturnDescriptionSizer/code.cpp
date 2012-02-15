//~~ void AddReturnDescriptionSizer(wxSizer* topSizer) [ResourceEdit] ~~

wxBoxSizer* box = new wxStaticBoxSizer(new wxStaticBox(this, -1, wxS("Return value description:")), wxHORIZONTAL);

ReturnDescriptionEditField = new wxTextCtrl(this, ID_RETURNDESCRIPTIONEDITFIELD, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
box->Add(ReturnDescriptionEditField, 1, wxEXPAND);

topSizer->Add(box, 1, wxEXPAND | wxALL, 10);

ReturnDescriptionEditField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/ReturnDescription"), wxEmptyString));
