//~~ void AddInitialStateSizer(wxSizer* topSizer, wxWindow* parent) [ResourceEdit] ~~
wxBoxSizer* box = new wxBoxSizer(wxHORIZONTAL);

box->Add(new wxStaticText(parent, -1, wxS("Event type:"), wxDefaultPosition, wxSize(60,15)));

eventType =  new wxTextCtrl(parent, -1);
eventType->SetMaxLength(128);

box->Add(eventType,3);

box->Add(new wxStaticText(parent, -1, wxS("Coder suffix:"), wxDefaultPosition, wxSize(80,15)),0,wxLEFT,10);

coderSuffix =  new wxTextCtrl(parent, -1);
coderSuffix->SetMaxLength(8);

box->Add(coderSuffix,1);

topSizer->Add(box,0,wxEXPAND|wxRIGHT|wxLEFT|wxTOP,10);

eventType->SetValue(wxConfigBase::Get()->Read(wxS("Astade/EventType"), wxEmptyString));
coderSuffix->SetValue(wxConfigBase::Get()->Read(wxS("Astade/CoderSuffix"), wxEmptyString));

box = new wxBoxSizer(wxHORIZONTAL);

box->Add(new wxStaticText(parent, -1, wxS("Initial state:"), wxDefaultPosition, wxSize(60,15)));

InitialState =  new wxTextCtrl(parent, -1);
InitialState->SetMaxLength(128);

box->Add(InitialState,1);

topSizer->Add(box,0,wxEXPAND|wxRIGHT|wxLEFT|wxTOP,10);

InitialState->SetValue(wxConfigBase::Get()->Read(wxS("Astade/InitialState"),wxEmptyString));
