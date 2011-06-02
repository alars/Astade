//~~ void CallStatechartCoder(wxCommandEvent& event) [AstadeFrame] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
theConfig->Flush(); // save last changes, because the Coder may read it from file!

wxTreeItemId anID = myTree->GetSelection();

AdeStatechart* aStateChart = dynamic_cast<AdeStatechart*>(myTree->GetItem(anID));
if (aStateChart == 0)
	wxLogFatalError("Cannot generate, because the item is no Statechart");

wxFileName component(theConfig->Read("TreeView/ActiveComponent"));
component.AppendDir("auto");
component.SetName(myTree->GetItem(anID)->GetName());
component.SetExt("cpp");

wxFileName coder(theConfig->Read("Tools/StatechartCoder"));
// Add the coder suffix to the name
wxString coderBaseName = coder.GetName();
coderBaseName += aStateChart->GetCoderSuffix();
coder.SetName(coderBaseName);

wxString callName = "\"" + coder.GetFullPath() + "\" " +
		"\"" + myTree->GetItem(anID)->GetFileName().GetFullPath() + "\" " +
		"\"" + component.GetFullPath() + "\"";

AstadeChildProcess* anAstadeChildProcess = new AstadeChildProcess(this);
anAstadeChildProcess->Redirect();

wxExecute(callName, wxEXEC_ASYNC, anAstadeChildProcess);
