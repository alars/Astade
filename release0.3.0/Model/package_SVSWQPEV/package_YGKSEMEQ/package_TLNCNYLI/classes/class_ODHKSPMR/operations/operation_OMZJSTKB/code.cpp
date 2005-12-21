wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName editor(theConfig->Read("Tools/CodeEdit"));

wxTreeItemId aID = myTree->GetSelection();

wxFileName component(theConfig->Read("TreeView/ActiveComponent"));
component.AppendDir("auto");
component.SetName(myTree->GetItem(aID)->GetName());
component.SetExt("cpp");


wxString callName = "\"" + editor.GetFullPath() + "\" " + "\"" + component.GetFullPath() + "\"";

AstadeChildProcess* aAstadeChildProcess = new AstadeChildProcess(aID, myTree);
wxExecute(callName, wxEXEC_ASYNC, aAstadeChildProcess);