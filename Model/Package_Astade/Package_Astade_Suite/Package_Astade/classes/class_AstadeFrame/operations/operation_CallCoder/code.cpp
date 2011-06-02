//~~ void CallCoder(wxCommandEvent& event) [AstadeFrame] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
theConfig->Flush(); // save last changes, because the Coder may read it from file!

wxTreeItemId anID = myTree->GetSelection();

wxFileName component(theConfig->Read("TreeView/ActiveComponent"));
component.AppendDir("auto");
component.SetName(myTree->GetItem(anID)->GetName());

AdeClass* theClass = dynamic_cast<AdeClass*>(myTree->GetItem(anID));
wxString callName;

if (theClass && theClass->codingLanguage() == CODE_C)
{
	callName = "\"" + theConfig->Read("Tools/CCoder") + "\" " +
			"\"" + myTree->GetItem(anID)->GetFileName().GetFullPath() + "\" " +
			"\"" + component.GetFullPath() + "\"";
}
else
{
	callName = "\"" + theConfig->Read("Tools/Coder") + "\" " +
			"\"" + myTree->GetItem(anID)->GetFileName().GetFullPath() + "\" " +
			"\"" + component.GetFullPath() + "\"";
}
component.SetExt(theClass->GetImpExtension());

AstadeChildProcess* anAstadeChildProcess = new AstadeChildProcess(this);
anAstadeChildProcess->Redirect();

wxExecute(callName, wxEXEC_ASYNC, anAstadeChildProcess);
