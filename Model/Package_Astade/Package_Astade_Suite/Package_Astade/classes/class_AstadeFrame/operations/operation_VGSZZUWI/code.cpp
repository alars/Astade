//~~ void DisplayCompositeStructure(wxCommandEvent& event) [AstadeFrame] ~~
		wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName coder(theConfig->Read("Tools/CompositeStructureViewPath"));

wxTreeItemId aID = myTree->GetSelection();

wxString callName = "\"" + coder.GetFullPath() + "\" " +
		"\"" + myTree->GetItem(aID)->GetFileName().GetFullPath() + "\"";

AstadeChildProcess* aAstadeChildProcess = new AstadeChildProcess(this);
//aAstadeChildProcess->Redirect();

wxExecute(callName, wxEXEC_ASYNC, aAstadeChildProcess);
