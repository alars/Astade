wxTreeItemId aID = myTree->GetSelection();
wxFileName path = myTree->GetItem(aID)->GetFileName();
int type = myTree->GetItem(aID)->GetType();

wxConfigBase* theConfig = wxConfigBase::Get();

wxFileName OperationEditor;

if (type==ITEM_IS_SEQUENCE)
	OperationEditor = theConfig->Read("Tools/SequencesPath");
else
if (type==ITEM_IS_USECASE)
	OperationEditor = theConfig->Read("Tools/UseCasesPath");
else
	OperationEditor = theConfig->Read("Tools/CodeEdit");

wxString callName = OperationEditor.GetFullPath()+" \""+path.GetFullPath()+"\"";

AstadeChildProcess* aAstadeChildProcess = new AstadeChildProcess(this);

wxExecute(callName, wxEXEC_ASYNC, aAstadeChildProcess);