wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName coder(theConfig->Read("Tools/Coder"));
theConfig->Flush(); // save last changes, because the Coder may read it from file!

wxTreeItemId aID = myTree->GetSelection();

wxFileName component(theConfig->Read("TreeView/ActiveComponent"));
component.AppendDir("auto");
component.SetName(myTree->GetItem(aID)->GetName());
component.SetExt("cpp");

wxString callName = "\"" + coder.GetFullPath() + "\" " +
	"\"" + myTree->GetItem(aID)->GetFileName().GetFullPath() + "\" " +
	"\"" + component.GetFullPath() + "\"";

AstadeChildProcess* aAstadeChildProcess = new AstadeChildProcess(this);
aAstadeChildProcess->Redirect();

wxExecute(callName, wxEXEC_ASYNC, aAstadeChildProcess);
