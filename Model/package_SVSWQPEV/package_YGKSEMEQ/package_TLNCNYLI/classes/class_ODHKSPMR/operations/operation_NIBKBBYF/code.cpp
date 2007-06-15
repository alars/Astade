wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName coder(theConfig->Read("Tools/StatechartCoder"));

wxTreeItemId aID = myTree->GetSelection();

wxFileName component(theConfig->Read("TreeView/ActiveComponent"));
component.AppendDir("auto");
component.SetName(myTree->GetItem(aID)->GetName());
component.SetExt("cpp");

AdeStatechart* aStateChart = dynamic_cast<AdeStatechart*>(myTree->GetItem(aID));

if (aStateChart==0)
	wxLogFatalError("Cannot generate, because the item is no Statechart");

// Add the coder suffix to the name
wxString coderBaseName = coder.GetName();
coderBaseName += aStateChart->GetCoderSuffix();
coder.SetName(coderBaseName);

wxString callName = "\"" + coder.GetFullPath() + "\" " +
	"\"" + myTree->GetItem(aID)->GetFileName().GetFullPath() + "\" " +
	"\"" + component.GetFullPath() + "\"";

AstadeChildProcess* aAstadeChildProcess = new AstadeChildProcess(this);
aAstadeChildProcess->Redirect();

wxExecute(callName, wxEXEC_ASYNC, aAstadeChildProcess);
