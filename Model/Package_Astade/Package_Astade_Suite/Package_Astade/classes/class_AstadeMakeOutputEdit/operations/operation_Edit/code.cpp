//~~ void Edit(wxCommandEvent& event) [AstadeMakeOutputEdit] ~~

wxConfigBase* theConfig = wxConfigBase::Get();

wxFileName OperationEditor = theConfig->Read(wxS("Tools/CodeEdit"));
wxString lineOption = theConfig->Read(wxS("Tools/CodeEdit/editLineOption"));

wxString callName;

if (event.GetId() == ID_EDIT_ERROR)
{
	callName = OperationEditor.GetFullPath();

	if (!lineOption.empty())
		callName += wxS(" ") + lineOption + m_errorLine;
	
	callName += wxS(" \"") + m_errorFile.GetFullPath() + wxS("\"");
	myAstadeTree->ShowNode(m_errorFile);
}
else
{
	callName = OperationEditor.GetFullPath();
	if (!lineOption.empty())
	{
		wxString lineStr;
		lineStr.sprintf(wxS("%d"), m_modelLine);	// Flawfinder: Ignore
		callName += wxS(" ") + lineOption + lineStr;
	}

	callName += wxS(" \"") + m_modelFile.GetFullPath() + wxS("\"");
	myAstadeTree->ShowNode(m_modelFile);
}

AstadeChildProcess* anAstadeChildProcess = new AstadeChildProcess(this);
wxExecute(callName, wxEXEC_ASYNC, anAstadeChildProcess);
