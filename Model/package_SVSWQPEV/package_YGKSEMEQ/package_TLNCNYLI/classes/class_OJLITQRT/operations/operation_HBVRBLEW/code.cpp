/* vi: set tabstop=4: */

wxConfigBase* theConfig = wxConfigBase::Get();

wxFileName OperationEditor = theConfig->Read("Tools/CodeEdit");
wxString lineOption = theConfig->Read("Tools/CodeEdit/editLineOption");

wxString callName;

if (event.GetId() == ID_EDIT_ERROR)
{
	callName = OperationEditor.GetFullPath() + " \"" + m_errorFile.GetFullPath() + "\"";
	myAstadeTree->ShowNode(m_errorFile);
	if (!lineOption.empty())
		callName += wxString(" ") + lineOption + m_errorLine;
}
else
{
	callName = OperationEditor.GetFullPath() + " \"" + m_modelFile.GetFullPath() + "\"";
	myAstadeTree->ShowNode(m_modelFile);
	if (!lineOption.empty())
	{
		wxString lineStr;
		lineStr.sprintf("%d", m_modelLine);
		callName += wxString(" ") + lineOption + lineStr;
	}
}

AstadeChildProcess* aAstadeChildProcess = new AstadeChildProcess(this);
wxExecute(callName, wxEXEC_ASYNC, aAstadeChildProcess);