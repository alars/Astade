		wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName coder(theConfig->Read("Tools/StatechartViewPath"));

wxTreeItemId aID = myTree->GetSelection();

wxString callName = "\"" + coder.GetFullPath() + "\" " +
		"\"" + myTree->GetItem(aID)->GetFileName().GetFullPath() + "\"";

AstadeChildProcess* aAstadeChildProcess = new AstadeChildProcess(this);
//aAstadeChildProcess->Redirect();

wxExecute(callName, wxEXEC_ASYNC, aAstadeChildProcess);
