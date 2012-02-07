//~~ void AddUseCaseDiagram(wxCommandEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = myTree->GetSelection();
wxFileName path = myTree->GetItem(anID)->GetFileName();
path.SetFullName(wxEmptyString);

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName SequenceEditor = theConfig->Read(wxS("Tools/UseCasesPath"));

wxString callName(SequenceEditor.GetFullPath() + wxS(" \"") + path.GetFullPath() + wxS("\""));

AstadeChildProcess* anAstadeChildProcess = new AstadeChildProcess(this);
wxExecute(callName, wxEXEC_ASYNC, anAstadeChildProcess);
