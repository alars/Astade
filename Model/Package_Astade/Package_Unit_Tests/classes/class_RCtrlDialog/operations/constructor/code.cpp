/* vi: set tabstop=4: */

SetMinSize(wxSize(600, 200));
SetSize(wxSize(600, 240));
wxBoxSizer *topsizer = new wxBoxSizer(wxVERTICAL);
SetSizer(topsizer);

wxArrayString selections;

selections.Add("RevisionControlNone");
selections.Add("RevisionControlSVN");
selections.Add("RevisionControlGit");
//selections.Add("RevisionControlCVS");

topsizer->Add(new wxRadioBox(this, ID_SELECT_REVISIONCONTROL, "Select Revision control", wxDefaultPosition, wxDefaultSize, selections), 0, wxEXPAND|wxALL, 10);

topsizer->AddStretchSpacer();

wxBoxSizer *aSizer = new wxBoxSizer(wxHORIZONTAL);
aSizer->Add(new wxButton(this, ID_SELECT_FILE, "Select file"), 0, wxLEFT, 10);
aSizer->Add(new wxButton(this, ID_SELECT_FOLDER, "Select directory"), 0, wxLEFT, 10);
topsizer->Add(aSizer, 0, wxEXPAND);

fileName = new wxTextCtrl(this, -1);
topsizer->Add(fileName, 0, wxEXPAND|wxALL, 10);

topsizer->AddStretchSpacer();

aSizer = new wxBoxSizer(wxHORIZONTAL);
addButton = new wxButton(this, ID_ADD, "Add");
aSizer->Add(addButton, 0, wxLEFT, 10);
aSizer->Add(new wxButton(this, ID_DELETE, "Delete"), 0, wxLEFT, 10);
aSizer->Add(new wxButton(this, ID_MOVE, "Move"), 0, wxLEFT, 10);
topsizer->Add(aSizer, 0, wxEXPAND|wxBOTTOM, 10);

Layout();
addButton->Enable(AdeRevisionControlBase::GetRevisionControlObject()->IsAddSupported());
