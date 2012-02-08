wxBoxSizer* box = new wxBoxSizer(wxHORIZONTAL);

box->Add(new wxStaticText(this, -1, wxS("Entry Action:"), wxDefaultPosition, wxSize(70,15)));

entryAction =  new wxTextCtrl(this, -1);
entryAction->SetMaxLength(128);

box->Add(entryAction,1);
entryAction->SetValue(wxConfigBase::Get()->Read(wxS("Astade/EntryAction"),wxEmptyString));

box->Add(new wxStaticText(this, -1, wxS("Exit Action:"), wxDefaultPosition, wxSize(65,15)), 0, wxLEFT, 10);

exitAction =  new wxTextCtrl(this, -1);
exitAction->SetMaxLength(128);

box->Add(exitAction,1);
exitAction->SetValue(wxConfigBase::Get()->Read(wxS("Astade/ExitAction"), wxEmptyString));

topSizer->Add(box,0,wxEXPAND|wxRIGHT|wxLEFT,10);
