wxTreeItemId aID = myTree->GetSelection();
wxFileName path = myTree->GetItem(aID)->GetFileName();
int type = myTree->GetItem(aID)->GetType();

wxConfigBase* theConfig = wxConfigBase::Get();

wxFileName OperationEditor;

switch (type & ITEM_TYPE_MASK)
{
	case ITEM_IS_SEQUENCE:
		OperationEditor = theConfig->Read("Tools/SequencesPath");
		break;

	case ITEM_IS_USECASE:
		OperationEditor = theConfig->Read("Tools/UseCasesPath");
		break;

	case ITEM_IS_DOXFILE:
		OperationEditor = theConfig->Read("Tools/DoxWizPath");
		break;

	default:
		if(theConfig->HasGroup("UserApps/"+path.GetExt()))
		{
			OperationEditor = theConfig->Read("UserApps/"+path.GetExt()+"/application");
		}
		else
		{
			OperationEditor = theConfig->Read("Tools/CodeEdit");
		}
}

wxString callName = OperationEditor.GetFullPath() + " \"" + path.GetFullPath() + "\"";

AstadeChildProcess* aAstadeChildProcess = new AstadeChildProcess(this);

wxExecute(callName, wxEXEC_ASYNC, aAstadeChildProcess);
