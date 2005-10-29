wxBoxSizer *button_sizer = new wxBoxSizer( wxHORIZONTAL );
topSizer->Add(button_sizer,0,wxEXPAND|wxALL|wxALIGN_BOTTOM,10);

button_sizer->Add(
	new wxButton(this, ID_CANCEL, "cancel"),0);

button_sizer->AddStretchSpacer();

button_sizer->Add(
	new wxButton(this, ID_SAVEANDEXIT, "Save and Exit"),0,wxALIGN_RIGHT);