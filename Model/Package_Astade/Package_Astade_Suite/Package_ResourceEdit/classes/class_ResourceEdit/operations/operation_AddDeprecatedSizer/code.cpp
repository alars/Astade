wxBoxSizer* depricatedSizer = new wxStaticBoxSizer(new wxStaticBox(this, -1, wxEmptyString), wxVERTICAL);

DeprecatedField = new wxCheckBox(this, ID_DEPRECATED, wxS("Deprecated"));
depricatedSizer->Add(DeprecatedField, 0, wxBOTTOM, 5);
DeprecatedField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Deprecated")) == wxS("yes"));

DeprecatedEditField = new wxTextCtrl(this, ID_DEPRECATEDEDITFIELD, wxS("") , wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
DeprecatedEditField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/DeprecatedDescription"), wxEmptyString));
DeprecatedEditField->Enable(DeprecatedField->IsChecked());

depricatedSizer->Add(DeprecatedEditField, 1, wxEXPAND);

topSizer->Add(depricatedSizer, 1, wxEXPAND|wxALL|wxALIGN_BOTTOM, 10);
