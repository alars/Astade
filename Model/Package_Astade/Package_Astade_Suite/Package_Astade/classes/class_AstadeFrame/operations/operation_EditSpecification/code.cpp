//~~ void EditSpecification(wxCommandEvent& event) [AstadeFrame] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName editor(theConfig->Read("Tools/CodeEdit"));

wxTreeItemId anID = myTree->GetSelection();

wxFileName component(theConfig->Read("TreeView/ActiveComponent"));
component.AppendDir("auto");
component.SetName(myTree->GetItem(anID)->GetName());
component.SetExt("h");

wxString callName = editor.GetFullPath() + " \"" + component.GetFullPath() + "\"";

AstadeChildProcess* anAstadeChildProcess = new AstadeChildProcess(this);
wxExecute(callName, wxEXEC_ASYNC, anAstadeChildProcess);
