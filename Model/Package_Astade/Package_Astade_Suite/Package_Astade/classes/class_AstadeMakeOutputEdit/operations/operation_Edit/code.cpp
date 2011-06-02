//~~ void Edit(wxCommandEvent& event) [AstadeMakeOutputEdit] ~~

wxConfigBase* theConfig = wxConfigBase::Get();

wxFileName OperationEditor = theConfig->Read("Tools/CodeEdit");
wxString lineOption = theConfig->Read("Tools/CodeEdit/editLineOption");

wxString callName;

if (event.GetId() == ID_EDIT_ERROR)
{
	callName = OperationEditor.GetFullPath();

	if (!lineOption.empty())
		callName += wxString(" ") + lineOption + m_errorLine;
	
	callName += " \"" + m_errorFile.GetFullPath() + "\"";
	myAstadeTree->ShowNode(m_errorFile);
}
else
{
	callName = OperationEditor.GetFullPath();
	if (!lineOption.empty())
	{
		wxString lineStr;
		lineStr.sprintf("%d", m_modelLine);	// Flawfinder: Ignore
		callName += wxString(" ") + lineOption + lineStr;
	}

	callName += " \"" + m_modelFile.GetFullPath() + "\"";
	myAstadeTree->ShowNode(m_modelFile);
}

AstadeChildProcess* anAstadeChildProcess = new AstadeChildProcess(this);
wxExecute(callName, wxEXEC_ASYNC, anAstadeChildProcess);
