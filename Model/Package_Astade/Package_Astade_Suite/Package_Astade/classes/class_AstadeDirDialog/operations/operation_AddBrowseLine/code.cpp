//~~ void AddBrowseLine(wxSizer* topsizer, wxString staticText, wxTextCtrl*& theTextControl, int browseButtonID) [AstadeDirDialog] ~~

topsizer->Add(new wxStaticText(this, 0, staticText), 0, wxRIGHT, 10);

theTextControl = new wxTextCtrl(this, 0, wxEmptyString);
topsizer->Add(theTextControl, 1, wxRIGHT | wxEXPAND, 10);

topsizer->Add(new wxButton(this, browseButtonID, wxS("browse")), 0, wxRIGHT, 10);
