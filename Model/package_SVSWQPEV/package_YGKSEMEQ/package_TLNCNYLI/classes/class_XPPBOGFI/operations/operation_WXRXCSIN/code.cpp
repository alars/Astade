wxBoxSizer *a_sizer = new wxBoxSizer(wxHORIZONTAL);
a_sizer->Add(
	new wxStaticText(this, 0, staticText, wxDefaultPosition, wxSize(90,20)), 0, wxRIGHT, 10);

theTextControl = new wxTextCtrl(this, 0, wxEmptyString);

a_sizer->Add(theTextControl, 1, wxRIGHT, 10);

a_sizer->Add(
	new wxButton(this, browseButtonID, "browse"), 0, wxRIGHT, 10);

topsizer->Add(a_sizer, 0, wxEXPAND|wxLEFT, 10);
