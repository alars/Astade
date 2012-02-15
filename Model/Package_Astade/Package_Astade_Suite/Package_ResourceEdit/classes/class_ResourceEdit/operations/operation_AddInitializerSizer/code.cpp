//~~ void AddInitializerSizer(wxSizer* topSizer) [ResourceEdit] ~~

wxBoxSizer* box = new wxStaticBoxSizer(new wxStaticBox(this, -1, wxS("Initializer:")), wxHORIZONTAL);

InitializerEditField = new wxTextCtrl(this, -1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
box->Add(InitializerEditField, 1, wxEXPAND);

topSizer->Add(box, 1, wxEXPAND|wxALL, 10);

InitializerEditField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Initializer"), wxEmptyString));
