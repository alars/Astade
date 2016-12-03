//~~ void CallCoder(wxCommandEvent& event) [AstadeFrame] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
theConfig->Flush(); // save last changes, because the Coder may read it from file!

wxTreeItemId anID = myTree->GetSelection();

wxFileName component(theConfig->Read(wxS("TreeView/ActiveComponent")));
component.AppendDir(wxS("auto"));
component.SetName(myTree->GetItem(anID)->GetName());

AdeClass* theClass = dynamic_cast<AdeClass*>(myTree->GetItem(anID));
wxString callName;

if (theClass && theClass->codingLanguage() == CODE_C)
{
	callName = wxS("\"") + theConfig->Read(wxS("Tools/CCoder")) + wxS("\" ") +
			wxS("\"") + myTree->GetItem(anID)->GetFileName().GetFullPath() + wxS("\" ") +
			wxS("\"") + component.GetFullPath() + wxS("\"");
}
else if (theClass && theClass->codingLanguage() == CODE_PYTHON)
{
	callName = wxS("\"") + theConfig->Read(wxS("Tools/PythonCoder")) + wxS("\" ") +
			wxS("\"") + myTree->GetItem(anID)->GetFileName().GetFullPath() + wxS("\" ") +
			wxS("\"") + component.GetFullPath() + wxS("\"");
}
else
{
	callName = wxS("\"") + theConfig->Read(wxS("Tools/Coder")) + wxS("\" ") +
			wxS("\"") + myTree->GetItem(anID)->GetFileName().GetFullPath() + wxS("\" ") +
			wxS("\"") + component.GetFullPath() + wxS("\"");
}

component.SetExt(theClass->GetImpExtension());

AstadeChildProcess* anAstadeChildProcess = new AstadeChildProcess(this);
anAstadeChildProcess->Redirect();

wxExecute(callName, wxEXEC_ASYNC, anAstadeChildProcess);
