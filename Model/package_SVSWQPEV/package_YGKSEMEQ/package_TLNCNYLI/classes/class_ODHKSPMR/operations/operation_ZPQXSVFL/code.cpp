wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName viewer(theConfig->Read("Tools/HtmlBrowser"));

wxTreeItemId aID = myTree->GetSelection();

wxString callName = "\"" + viewer.GetFullPath() + "\" " +
	"\"" + myTree->GetItem(aID)->GetFileName().GetFullPath() + "\" ";

AstadeChildProcess* aAstadeChildProcess = new AstadeChildProcess(this);
aAstadeChildProcess->Redirect();

wxExecute(callName, wxEXEC_ASYNC, aAstadeChildProcess);