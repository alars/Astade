//~~ void DisplayStatechart(wxCommandEvent& event) [AstadeFrame] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName coder(theConfig->Read("Tools/StatechartViewPath"));

wxTreeItemId anID = myTree->GetSelection();

wxString callName = "\"" + coder.GetFullPath() + "\" " +
		"\"" + myTree->GetItem(anID)->GetFileName().GetFullPath() + "\"";

AstadeChildProcess* anAstadeChildProcess = new AstadeChildProcess(this);
//anAstadeChildProcess->Redirect();
wxExecute(callName, wxEXEC_ASYNC, anAstadeChildProcess);
