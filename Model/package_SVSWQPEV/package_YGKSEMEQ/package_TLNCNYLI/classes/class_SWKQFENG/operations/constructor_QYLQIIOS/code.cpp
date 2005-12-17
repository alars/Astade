SetMinSize(wxSize(100,200));
wxBoxSizer *topSizer = new wxBoxSizer( wxVERTICAL );
SetSizer( topSizer );

wxBoxSizer* box = new wxStaticBoxSizer( new wxStaticBox(this, -1, wxString("attributes:")), wxVERTICAL );
topSizer->Add(box,1,wxEXPAND);

box = new wxStaticBoxSizer( new wxStaticBox(this, -1, wxString("operations:")), wxVERTICAL );
topSizer->Add(box,1,wxEXPAND);

topSizer->Add(
	new wxButton(this, ID_OBJECTMODELDIAGRAM, "show"),0);
