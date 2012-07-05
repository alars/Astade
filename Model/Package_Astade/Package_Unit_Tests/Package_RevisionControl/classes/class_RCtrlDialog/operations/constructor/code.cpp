//~~ RCtrlDialog() [RCtrlDialog] ~~

SetMinSize(wxSize(600, 200));
SetSize(wxSize(600, 240));
wxBoxSizer *topsizer = new wxBoxSizer(wxVERTICAL);
SetSizer(topsizer);

wxArrayString selections;

selections.Add(wxS("RevisionControlNone"));
selections.Add(wxS("RevisionControlSVN"));
selections.Add(wxS("RevisionControlGit"));
//selections.Add(wxS("RevisionControlCVS"));

topsizer->Add(new wxRadioBox(this, ID_SELECT_REVISIONCONTROL, wxS("Select Revision control"), wxDefaultPosition, wxDefaultSize, selections), 0, wxEXPAND|wxALL, 10);

topsizer->AddStretchSpacer();

wxBoxSizer *aSizer = new wxBoxSizer(wxHORIZONTAL);
aSizer->Add(new wxButton(this, ID_SELECT_FILE, wxS("Select file")), 0, wxLEFT, 10);
aSizer->Add(new wxButton(this, ID_SELECT_FOLDER, wxS("Select directory")), 0, wxLEFT, 10);
topsizer->Add(aSizer, 0, wxEXPAND);

fileName = new wxTextCtrl(this, -1);
topsizer->Add(fileName, 0, wxEXPAND|wxALL, 10);

topsizer->AddStretchSpacer();

aSizer = new wxBoxSizer(wxHORIZONTAL);
addButton = new wxButton(this, ID_ADD, wxS("Add"));
aSizer->Add(addButton, 0, wxLEFT, 10);
aSizer->Add(new wxButton(this, ID_DELETE, wxS("Delete")), 0, wxLEFT, 10);
aSizer->Add(new wxButton(this, ID_MOVE, wxS("Move")), 0, wxLEFT, 10);
topsizer->Add(aSizer, 0, wxEXPAND|wxBOTTOM, 10);

Layout();
addButton->Enable(AdeRevisionControlBase::GetRevisionControlObject()->IsAddSupported());
