//~~ void AddTransitionSizer(wxSizer* topSizer) [ResourceEdit] ~~
wxBoxSizer *relations = new wxBoxSizer(wxHORIZONTAL);
topSizer->Add(relations, 0, wxEXPAND|wxRIGHT|wxLEFT, 10);

wxArrayString arrayStringFor_WxComboBox1;
arrayStringFor_WxComboBox1.Add(wxS("Normal"));
arrayStringFor_WxComboBox1.Add(wxS("Internal"));
arrayStringFor_WxComboBox1.Add(wxS("Self"));
arrayStringFor_WxComboBox1.Add(wxS("Terminate"));

transitionType = new wxComboBox(this, ID_AGGREGATIONTYPE ,wxEmptyString ,wxDefaultPosition, wxDefaultSize, arrayStringFor_WxComboBox1, wxCB_READONLY);

relations->Add(transitionType, 1);

destinationText = new wxStaticText(this, 0, wxS("Destination:"));
relations->Add(destinationText, 0, wxRIGHT|wxLEFT, 10);

destinationEditField = new wxTextCtrl(this, -1);
relations->Add(destinationEditField ,1);

relations = new wxBoxSizer(wxHORIZONTAL);
topSizer->Add(relations, 0, wxEXPAND|wxRIGHT|wxLEFT|wxTOP, 10);

relations->Add(new wxStaticText(this, 0, wxS("Trigger:"), wxDefaultPosition, wxSize(60, 15)), 0);

triggerEditField = new wxTextCtrl(this, -1);
relations->Add(triggerEditField, 1);

allCheckbox = new wxCheckBox(this, ID_ALL, wxS("all"));
relations->Add(allCheckbox);

relations = new wxBoxSizer(wxHORIZONTAL);
topSizer->Add(relations, 0, wxEXPAND|wxRIGHT|wxLEFT, 10);

relations->Add(new wxStaticText(this, 0, wxS("Guard:"), wxDefaultPosition, wxSize(60, 15)), 0);

guardEditField = new wxTextCtrl(this, -1);
relations->Add(guardEditField, 1);

transitionType->SetValue(wxConfigBase::Get()->Read(wxS("Astade/TransitionType"), wxEmptyString));
destinationEditField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/DestinationState"), wxEmptyString));
guardEditField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Guard"), wxEmptyString));
triggerEditField->SetValue(wxConfigBase::Get()->Read(wxS("Astade/Trigger"), wxEmptyString));
allCheckbox->SetValue(wxConfigBase::Get()->Read(wxS("Astade/EventAll")) == wxS("yes"));