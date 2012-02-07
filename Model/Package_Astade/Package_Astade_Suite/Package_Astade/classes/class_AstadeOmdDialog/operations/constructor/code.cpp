//~~ AstadeOmdDialog(wxWindow* parent) [AstadeOmdDialog] ~~

wxBoxSizer *topSizer = new wxBoxSizer(wxVERTICAL);
SetSizer(topSizer);

wxArrayString text;
text.Add(wxS("none"));
text.Add(wxS("public"));
text.Add(wxS("public + protected"));
text.Add(wxS("all"));

attributesRadioBox = new wxRadioBox(this, -1, wxS("attributes:"), wxDefaultPosition, wxDefaultSize, text, 1);
topSizer->Add(attributesRadioBox, 1, wxALL|wxEXPAND, 10);

operationsRadioBox = new wxRadioBox(this, -1, wxS("operations:"), wxDefaultPosition, wxDefaultSize, text, 1);
topSizer->Add(operationsRadioBox, 1, wxLEFT | wxRIGHT | wxEXPAND, 10);

externalCheckBox = new wxCheckBox(this, -1, wxS("include classes outside this scope"));
topSizer->Add(externalCheckBox, 0, wxALL, 10);

notInComponentCheckBox = new wxCheckBox(this, -1, wxS("include classes outside active component"));
topSizer->Add(notInComponentCheckBox, 0, wxLEFT | wxBOTTOM | wxRIGHT, 10);

drawPortsCheckBox = new wxCheckBox(this, -1, wxS("draw ports of classes"));
topSizer->Add(drawPortsCheckBox, 0, wxLEFT | wxBOTTOM | wxRIGHT, 10);

wxBoxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);
topSizer->Add(button_sizer, 0, wxEXPAND | wxALL | wxALIGN_BOTTOM, 10);
button_sizer->AddStretchSpacer();
button_sizer->Add(new wxButton(this, wxID_CANCEL));
button_sizer->AddSpacer(10);
button_sizer->Add(new wxButton(this, wxID_OK), 0, wxALIGN_RIGHT);

topSizer->SetSizeHints(this);
