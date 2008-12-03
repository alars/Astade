		wxConfigBase* theConfig = wxConfigBase::Get();
theConfig->Flush(); // save last changes, because the Coder may read it from file!

wxTreeItemId aID = myTree->GetSelection();

wxFileName component(theConfig->Read("TreeView/ActiveComponent"));
component.AppendDir("auto");
component.SetName(myTree->GetItem(aID)->GetName());

AdeClass* theClass = dynamic_cast<AdeClass*>(myTree->GetItem(aID));
wxString callName;

if (theClass && theClass->IsCCoded())
{
	component.SetExt("cpp");
	callName = "\"" + theConfig->Read("Tools/CCoder") + "\" " +
			"\"" + myTree->GetItem(aID)->GetFileName().GetFullPath() + "\" " +
			"\"" + component.GetFullPath() + "\"";
}
else
{
	component.SetExt("c");
	callName = "\"" + theConfig->Read("Tools/Coder") + "\" " +
			"\"" + myTree->GetItem(aID)->GetFileName().GetFullPath() + "\" " +
			"\"" + component.GetFullPath() + "\"";
}

AstadeChildProcess* aAstadeChildProcess = new AstadeChildProcess(this);
aAstadeChildProcess->Redirect();

wxExecute(callName, wxEXEC_ASYNC, aAstadeChildProcess);
