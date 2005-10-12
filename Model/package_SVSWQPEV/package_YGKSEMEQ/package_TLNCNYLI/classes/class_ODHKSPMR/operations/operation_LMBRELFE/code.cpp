wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName coder(theConfig->Read("Tools/OmdViewPath"));

wxTreeItemId aID = myTree->GetSelection();

wxString callName = "\"" + coder.GetFullPath() + "\" " +
	"\"" + myTree->GetItem(aID)->GetFileName().GetFullPath() + "\"";

AstadeChildProcess* aAstadeChildProcess = new AstadeChildProcess(aID, myTree);
//aAstadeChildProcess->Redirect();

wxExecute(callName, wxEXEC_ASYNC, aAstadeChildProcess);
