wxTreeItemId aID = myTree->GetSelection();
wxFileName path = myTree->GetItem(aID)->GetFileName();

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName OperationEditor = theConfig->Read("Tools/CodeEdit");

switch (event.GetId())
{
	case ID_EDITSPECPROLOG: path.SetFullName("prolog.h"); break;
	case ID_EDITIMPPROLOG: path.SetFullName("prolog.cpp"); break;
	case ID_EDITSPECEPILOG: path.SetFullName("epilog.h"); break;
	case ID_EDITIMPGEPILOG: path.SetFullName("epilog.cpp"); break;
}

wxString callName = OperationEditor.GetFullPath()+" \""+path.GetFullPath()+"\"";

AstadeChildProcess* aAstadeChildProcess = new AstadeChildProcess(this);

wxExecute(callName, wxEXEC_ASYNC, aAstadeChildProcess);