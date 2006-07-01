wxTreeItemId aID = myTree->GetSelection();
wxFileName path = myTree->GetItem(aID)->GetFileName();

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName SequenceEditor = theConfig->Read("Tools/SequencesPath");

path.SetFullName("");

wxString callName = SequenceEditor.GetFullPath()+" \""+path.GetFullPath()+"\"";

AstadeChildProcess* aAstadeChildProcess = new AstadeChildProcess(this);

wxExecute(callName, wxEXEC_ASYNC, aAstadeChildProcess);