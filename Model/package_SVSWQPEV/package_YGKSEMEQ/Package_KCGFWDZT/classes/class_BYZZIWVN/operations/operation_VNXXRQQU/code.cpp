wxBoxSizer* box = new wxBoxSizer(wxHORIZONTAL);

box->Add(new wxStaticText(this, -1 ,"Event type:",wxDefaultPosition,wxSize(60,15)));

eventType =  new wxTextCtrl(this, -1);
eventType->SetMaxLength(128);

box->Add(eventType,1);

topSizer->Add(box,0,wxEXPAND|wxRIGHT|wxLEFT,10);

eventType->SetValue(wxConfigBase::Get()->Read("Astade/EventType",wxEmptyString));

box = new wxBoxSizer(wxHORIZONTAL);

box->Add(new wxStaticText(this, -1 ,"Initial state:",wxDefaultPosition,wxSize(60,15)));

InitialState =  new wxTextCtrl(this, -1);
InitialState->SetMaxLength(128);

box->Add(InitialState,1);

topSizer->Add(box,0,wxEXPAND|wxRIGHT|wxLEFT|wxTOP,10);

InitialState->SetValue(wxConfigBase::Get()->Read("Astade/InitialState",wxEmptyString));