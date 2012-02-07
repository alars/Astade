//~~ void DisplayCompositeStructure(wxCommandEvent& event) [AstadeFrame] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName coder(theConfig->Read(wxS("Tools/CompositeStructureViewPath")));

wxTreeItemId anID = myTree->GetSelection();

wxString callName(wxS("\"") + coder.GetFullPath() + wxS("\" ") +
		wxS("\"") + myTree->GetItem(anID)->GetFileName().GetFullPath() + wxS("\""));

AstadeChildProcess* anAstadeChildProcess = new AstadeChildProcess(this);
//anAstadeChildProcess->Redirect();

wxExecute(callName, wxEXEC_ASYNC, anAstadeChildProcess);
