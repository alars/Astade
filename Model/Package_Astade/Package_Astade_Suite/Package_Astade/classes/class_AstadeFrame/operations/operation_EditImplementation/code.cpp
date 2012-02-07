//~~ void EditImplementation(wxCommandEvent& event) [AstadeFrame] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName editor(theConfig->Read(wxS("Tools/CodeEdit")));

wxTreeItemId anID = myTree->GetSelection();

wxFileName component(theConfig->Read(wxS("TreeView/ActiveComponent")));
component.AppendDir(wxS("auto"));
component.SetName(myTree->GetItem(anID)->GetName());
component.SetExt(wxS("c"));

if (!component.FileExists())
	component.SetExt(wxS("cpp"));

wxString callName(editor.GetFullPath() + wxS(" \"") + component.GetFullPath() + wxS("\""));

AstadeChildProcess* anAstadeChildProcess = new AstadeChildProcess(this);
wxExecute(callName, wxEXEC_ASYNC, anAstadeChildProcess);
