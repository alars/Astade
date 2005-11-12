wxBoxSizer* box = new wxBoxSizer(wxHORIZONTAL);

box->Add(new wxStaticText(this, -1 ,"Initial state:",wxDefaultPosition,wxSize(60,15)));

InitialState =  new wxTextCtrl(this, -1);
InitialState->SetMaxLength(128);

box->Add(InitialState,1);

topSizer->Add(box,0,wxEXPAND|wxRIGHT|wxLEFT,10);

InitialState->SetValue(wxConfigBase::Get()->Read("Astade/InitialState",wxEmptyString));

box = new wxBoxSizer(wxHORIZONTAL);

box->Add(new wxStaticText(this, -1 ,"Action 1:",wxDefaultPosition,wxSize(60,15)));

action1 =  new wxTextCtrl(this, -1);
action1->SetMaxLength(128);

box->Add(action1,1);
action1->SetValue(wxConfigBase::Get()->Read("Astade/Action1",wxEmptyString));

box->Add(new wxStaticText(this, -1 ,"Action 2:",wxDefaultPosition,wxSize(60,15)),0,wxLEFT,10);

action2 =  new wxTextCtrl(this, -1);
action2->SetMaxLength(128);

box->Add(action2,1);
action2->SetValue(wxConfigBase::Get()->Read("Astade/Action2",wxEmptyString));

topSizer->Add(box,0,wxEXPAND|wxRIGHT|wxLEFT|wxTOP,10);