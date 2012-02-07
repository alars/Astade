//~~ void Edit(wxCommandEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = myTree->GetSelection();
wxFileName path = myTree->GetItem(anID)->GetFileName();
int type = myTree->GetItem(anID)->GetType();

wxConfigBase* theConfig = wxConfigBase::Get();

wxFileName OperationEditor;

switch (type & ITEM_TYPE_MASK)
{
	case ITEM_IS_SEQUENCE:
		OperationEditor = theConfig->Read(wxS("Tools/SequencesPath"));
		break;

	case ITEM_IS_USECASE:
		OperationEditor = theConfig->Read(wxS("Tools/UseCasesPath"));
		break;

	case ITEM_IS_DOXFILE:
		OperationEditor = theConfig->Read(wxS("Tools/DoxWizPath"));
		break;

	default:
		if (!path.GetExt().IsEmpty() && theConfig->HasGroup(wxS("UserApps/") + path.GetExt()))
		{
			OperationEditor = theConfig->Read(wxS("UserApps/") + path.GetExt() + wxS("/application"));
		}
		else
		{
			InsertPrototype(anID);
			OperationEditor = theConfig->Read(wxS("Tools/CodeEdit"));
		}
}

wxString callName(OperationEditor.GetFullPath() + wxS(" \"") + path.GetFullPath() + wxS("\""));

AstadeChildProcess* anAstadeChildProcess = new AstadeChildProcess(this);
wxExecute(callName, wxEXEC_ASYNC, anAstadeChildProcess);
