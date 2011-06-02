//~~ void Edit(wxCommandEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = myTree->GetSelection();
wxFileName path = myTree->GetItem(anID)->GetFileName();
int type = myTree->GetItem(anID)->GetType();

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
		if (!path.GetExt().IsEmpty() && theConfig->HasGroup("UserApps/" + path.GetExt()))
		{
			OperationEditor = theConfig->Read("UserApps/" + path.GetExt() + "/application");
		}
		else
		{
			InsertPrototype(anID);
			OperationEditor = theConfig->Read("Tools/CodeEdit");
		}
}

wxString callName = OperationEditor.GetFullPath() + " \"" + path.GetFullPath() + "\"";

AstadeChildProcess* anAstadeChildProcess = new AstadeChildProcess(this);
wxExecute(callName, wxEXEC_ASYNC, anAstadeChildProcess);
