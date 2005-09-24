wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName coder(theConfig->Read("Tools/Coder"));

wxTreeItemId aID = myTree->GetSelection();

wxFileName component(theConfig->Read("TreeView/ActiveComponent"));
component.AppendDir("auto");
component.SetName(myTree->GetItem(aID)->GetName());
component.SetExt("cpp");

wxString callName = coder.GetFullPath()+
					" \""+myTree->GetItem(aID)->GetFileName().GetFullPath()+"\" " +
					" \""+component.GetFullPath()+"\" ";

wxExecute(callName, wxEXEC_ASYNC, new AstadeChildProcess(aID,myTree));