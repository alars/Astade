//~~ void AddInitializerSizer(wxSizer* topSizer, wxWindow* parent) [ResourceEdit] ~~

wxBoxSizer* box = new wxStaticBoxSizer(new wxStaticBox(parent, -1, wxS("Initializer:")), wxHORIZONTAL);

InitializerEditField = new wxTextCtrl(parent, -1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
box->Add(InitializerEditField, 1, wxEXPAND);

topSizer->Add(box, 1, wxEXPAND|wxALL, 10);

InitializerEditField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Initializer"), wxEmptyString));
