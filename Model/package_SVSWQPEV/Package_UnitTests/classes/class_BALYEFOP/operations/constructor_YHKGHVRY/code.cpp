/* vi: set tabstop=4: */

SetMinSize(wxSize(600, 200));
SetSize(wxSize(600, 200));
wxBoxSizer *topsizer = new wxBoxSizer(wxVERTICAL);
SetSizer(topsizer);

wxArrayString selections;

selections.Add("RevisionControlNone");
selections.Add("RevisionControlSVN");
//selections.Add("RevisionControlGit");
//selections.Add("RevisionControlCVS");

topsizer->Add(
	new wxRadioBox(this,ID_SELECT_REVISIONCONTROL,"Select Revision control",wxDefaultPosition,wxDefaultSize,selections)
	,0,wxEXPAND);

topsizer->AddStretchSpacer();

wxBoxSizer *aSizer = new wxBoxSizer(wxHORIZONTAL);

aSizer->Add(new wxButton(this,ID_SELECT_FILE,"Select file"));
aSizer->Add(new wxButton(this,ID_SELECT_FOLDER,"Select folder"));

fileName = new wxTextCtrl(this,-1);
topsizer->Add(aSizer,0,wxEXPAND);
topsizer->Add(fileName,0,wxEXPAND);

topsizer->AddStretchSpacer();

aSizer = new wxBoxSizer(wxHORIZONTAL);

aSizer->Add(new wxButton(this,ID_CHECK,"Check"));
aSizer->AddStretchSpacer();
existCheckBox = new wxCheckBox(this,-1,"File exists?");
existCheckBox->Disable();
aSizer->Add(existCheckBox);
aSizer->AddStretchSpacer();
inRepositoryCheckBox = new wxCheckBox(this,-1,"in repository?");
inRepositoryCheckBox->Disable();
aSizer->Add(inRepositoryCheckBox);
aSizer->AddStretchSpacer();
locallyChangedCheckBox = new wxCheckBox(this,-1,"locally changed?");
locallyChangedCheckBox->Disable();
aSizer->Add(locallyChangedCheckBox);

topsizer->Add(aSizer,0,wxEXPAND);

topsizer->AddStretchSpacer();

aSizer = new wxBoxSizer(wxHORIZONTAL);

aSizer->Add(new wxButton(this, ID_ADD, "Add"));
aSizer->AddStretchSpacer();
aSizer->Add(new wxButton(this,-1,"Commit"));
aSizer->AddStretchSpacer();
aSizer->Add(new wxButton(this, ID_DELETE, "Delete"));
aSizer->AddStretchSpacer();
aSizer->Add(new wxButton(this, ID_MOVE, "Move"));
aSizer->AddStretchSpacer();
aSizer->Add(new wxButton(this,-1,"Revert"));
aSizer->AddStretchSpacer();
aSizer->Add(new wxButton(this,-1,"Update"));

topsizer->Add(aSizer,0,wxEXPAND);

Layout();