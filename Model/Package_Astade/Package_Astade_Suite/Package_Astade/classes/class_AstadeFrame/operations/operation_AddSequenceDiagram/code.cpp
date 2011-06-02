//~~ void AddSequenceDiagram(wxCommandEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = myTree->GetSelection();
wxFileName path = myTree->GetItem(anID)->GetFileName();
path.SetFullName("");

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName SequenceEditor = theConfig->Read("Tools/SequencesPath");

wxString callName = SequenceEditor.GetFullPath() + " \"" + path.GetFullPath() + "\"";

AstadeChildProcess* anAstadeChildProcess = new AstadeChildProcess(this);
wxExecute(callName, wxEXEC_ASYNC, anAstadeChildProcess);
