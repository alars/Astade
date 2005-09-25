wxTreeItemId aID = myTree->GetSelection();
wxFileName path = myTree->GetItem(aID)->GetFileName();

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName OperationEditor = theConfig->Read("Tools/CodeEdit");

wxString callName = OperationEditor.GetFullPath()+" \""+path.GetFullPath()+"\"";

AstadeChildProcess* aAstadeChildProcess = new AstadeChildProcess(aID,myTree);

wxExecute(callName, wxEXEC_ASYNC, aAstadeChildProcess);