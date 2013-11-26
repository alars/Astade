//~~ void AddDescriptionSizer(wxSizer* topSizer, wxWindow* parent) [ResourceEdit] ~~

wxBoxSizer* box = new wxStaticBoxSizer(new wxStaticBox(parent, -1, wxS("Description:")), wxHORIZONTAL);

DescriptionEditField = new wxTextCtrl(parent, ID_DESCRIPTIONEDITFIELD, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
box->Add(DescriptionEditField, 1, wxEXPAND);

topSizer->Add(box, 1, wxEXPAND | wxALL, 10);

DescriptionEditField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Description"), wxEmptyString));
