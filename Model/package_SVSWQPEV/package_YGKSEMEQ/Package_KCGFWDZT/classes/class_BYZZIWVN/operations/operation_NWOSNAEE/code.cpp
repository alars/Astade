wxStaticText *eventText = new wxStaticText(this, -1, "event:", wxDefaultPosition, wxSize(45,15));
topSizer->Add(eventText, 0, wxALIGN_LEFT|wxLEFT, 10);

EventEditField = new wxTextCtrl(this, -1);
EventEditField->SetMaxLength(256);

topSizer->Add(EventEditField, 1, wxLEFT, 10);

EventEditField->SetValue(wxConfigBase::Get()->Read("Astade/EventType", wxEmptyString));