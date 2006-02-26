wxBoxSizer *topSizer = new wxBoxSizer(wxVERTICAL);
SetSizer(topSizer);

wxArrayString text;
text.Add("none");
text.Add("public");
text.Add("public + protected");
text.Add("all");

attributesRadioBox = new wxRadioBox(this, -1, wxString("attributes:"),wxDefaultPosition,wxDefaultSize, text, 1);
topSizer->Add(attributesRadioBox, 1, wxEXPAND, 10);

operationsRadioBox =  new wxRadioBox(this, -1, wxString("operations:"),wxDefaultPosition,wxDefaultSize, text, 1);
topSizer->Add(operationsRadioBox, 1, wxEXPAND);

externalCheckBox = new wxCheckBox(this, -1, "include classes outside this scope");
topSizer->Add(externalCheckBox, 0, wxALL, 10);

notInComponentCheckBox = new wxCheckBox(this, -1, "include classes outside active component");
topSizer->Add(notInComponentCheckBox, 0, wxLEFT|wxBOTTOM, 10);

wxBoxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);
topSizer->Add(button_sizer, 0, wxEXPAND|wxALL|wxALIGN_BOTTOM, 10);
button_sizer->Add(new wxButton(this, wxID_CANCEL, "cancel"));
button_sizer->AddStretchSpacer();
button_sizer->Add(new wxButton(this, ID_OBJECTMODELDIAGRAM, "show"), 0, wxALIGN_RIGHT);

topSizer->SetSizeHints(this);
