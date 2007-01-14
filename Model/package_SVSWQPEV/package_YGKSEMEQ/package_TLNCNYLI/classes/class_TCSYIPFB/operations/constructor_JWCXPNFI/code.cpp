// Controls
sizerList_staticbox = new wxStaticBox(this, -1, "Applications");
lstApps = new wxListView(this, -1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_EDIT_LABELS|wxLC_SINGLE_SEL|wxLC_SORT_ASCENDING|wxSUNKEN_BORDER);
lstApps->InsertColumn(0, "Extension");
lstApps->InsertColumn(1, "Application");
lstApps->InsertColumn(2, "Icon");

btnAdd = new wxButton(this, ID_BUTTON_ADD, "&Add");
btnRemove = new wxButton(this, ID_BUTTON_REMOVE, "&Remove");
btnCancel = new wxButton(this, wxID_CANCEL);
btnOk = new wxButton(this, wxID_OK);

// Layout
wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);
wxBoxSizer* sizerAddRemove = new wxBoxSizer(wxHORIZONTAL);
wxBoxSizer* sizerCancelOk = new wxBoxSizer(wxHORIZONTAL);
wxStaticBoxSizer* sizerList = new wxStaticBoxSizer(sizerList_staticbox, wxVERTICAL);

sizerAddRemove->AddStretchSpacer();
sizerAddRemove->Add(btnAdd, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 10);
sizerAddRemove->AddStretchSpacer();
sizerAddRemove->Add(btnRemove, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 10);
sizerAddRemove->AddStretchSpacer();
sizerList->Add(lstApps, 1, wxALL|wxEXPAND, 2);
sizerList->Add(sizerAddRemove, 0, wxALL|wxEXPAND, 2);
topSizer->Add(sizerList, 1, wxALL|wxEXPAND, 5);

sizerCancelOk->AddStretchSpacer();
sizerCancelOk->Add(btnCancel,  0, wxRIGHT, 10);
sizerCancelOk->Add(btnOk, 0, wxALIGN_RIGHT | wxRIGHT, 10);
topSizer->Add(sizerCancelOk, 0, wxALL|wxEXPAND, 5);

topSizer->SetMinSize(wxSize(500, 450));
SetAutoLayout(true);
SetSizer(topSizer);

Layout();