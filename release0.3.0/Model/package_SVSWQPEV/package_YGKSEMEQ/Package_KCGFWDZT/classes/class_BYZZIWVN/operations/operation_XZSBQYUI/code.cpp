wxBoxSizer* box = new wxBoxSizer(wxHORIZONTAL);

box->Add(new wxStaticText(this, -1 ,"Action 1:",wxDefaultPosition,wxSize(50,15)));

action1 =  new wxTextCtrl(this, -1);
action1->SetMaxLength(128);

box->Add(action1,1);
action1->SetValue(wxConfigBase::Get()->Read("Astade/Action1",wxEmptyString));

box->Add(new wxStaticText(this, -1 ,"Action 2:",wxDefaultPosition,wxSize(50,15)),0,wxLEFT,10);

action2 =  new wxTextCtrl(this, -1);
action2->SetMaxLength(128);

box->Add(action2,1);
action2->SetValue(wxConfigBase::Get()->Read("Astade/Action2",wxEmptyString));

topSizer->Add(box,0,wxEXPAND|wxRIGHT|wxLEFT|wxTOP,10);



box = new wxBoxSizer(wxHORIZONTAL);

box->Add(new wxStaticText(this, -1 ,"Action 3:",wxDefaultPosition,wxSize(50,15)));

action3 =  new wxTextCtrl(this, -1);
action3->SetMaxLength(128);

box->Add(action3,1);
action3->SetValue(wxConfigBase::Get()->Read("Astade/Action3",wxEmptyString));

box->Add(new wxStaticText(this, -1 ,"Action 4:",wxDefaultPosition,wxSize(50,15)),0,wxLEFT,10);

action4 =  new wxTextCtrl(this, -1);
action4->SetMaxLength(128);

box->Add(action4,1);
action4->SetValue(wxConfigBase::Get()->Read("Astade/Action4",wxEmptyString));

topSizer->Add(box,0,wxEXPAND|wxRIGHT|wxLEFT,10);
