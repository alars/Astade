//~~ void AddConstraintSizer(wxSizer* topSizer, wxWindow* parent) [ResourceEdit] ~~

wxBoxSizer* box = new wxStaticBoxSizer(new wxStaticBox(parent, -1, wxS("Constraint:")), wxHORIZONTAL);

ConstraintEditField = new wxTextCtrl(parent, -1);
box->Add(ConstraintEditField, 1);

topSizer->Add(box, 0, wxEXPAND | wxALL, 10);

ConstraintEditField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Constraint"), wxEmptyString));
