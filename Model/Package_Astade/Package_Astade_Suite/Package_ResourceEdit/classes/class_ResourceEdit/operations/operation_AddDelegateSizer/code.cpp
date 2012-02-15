//~~ void AddDelegateSizer(wxSizer* topSizer) [ResourceEdit] ~~

wxBoxSizer *delegation = new wxBoxSizer(wxHORIZONTAL);
topSizer->Add(delegation, 0, wxEXPAND | wxRIGHT | wxLEFT, 10);

DelegationObjectText = new wxStaticText(this, 0, wxS("Object:"), wxDefaultPosition, wxSize(50, 15));
delegation->Add(DelegationObjectText, 0);

DelegationObject = new wxTextCtrl(this, -1);
delegation->Add(DelegationObject, 1);

delegation = new wxBoxSizer(wxHORIZONTAL);
topSizer->Add(delegation, 0, wxEXPAND | wxRIGHT | wxLEFT, 10);

DelegationPortText = new wxStaticText(this, 0, wxS("Port:"), wxDefaultPosition, wxSize(50, 15));
delegation->Add(DelegationPortText, 0);

DelegationPort = new wxTextCtrl(this, -1);
delegation->Add(DelegationPort, 1);

DelegationObject->SetValue(wxConfigBase::Get()->Read(wxS("Astade/DelegationObject"), wxEmptyString));
DelegationPort->SetValue(wxConfigBase::Get()->Read(wxS("Astade/DelegationPort"), wxEmptyString));
