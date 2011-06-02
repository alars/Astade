//~~ void EditImplementation(wxCommandEvent& event) [AstadeFrame] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName editor(theConfig->Read("Tools/CodeEdit"));

wxTreeItemId anID = myTree->GetSelection();

wxFileName component(theConfig->Read("TreeView/ActiveComponent"));
component.AppendDir("auto");
component.SetName(myTree->GetItem(anID)->GetName());
component.SetExt("c");

if (!component.FileExists())
	component.SetExt("cpp");

wxString callName = editor.GetFullPath() + " \"" + component.GetFullPath() + "\"";

AstadeChildProcess* anAstadeChildProcess = new AstadeChildProcess(this);
wxExecute(callName, wxEXEC_ASYNC, anAstadeChildProcess);
