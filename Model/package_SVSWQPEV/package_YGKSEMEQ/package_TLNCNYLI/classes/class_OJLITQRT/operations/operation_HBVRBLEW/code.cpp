wxConfigBase* theConfig = wxConfigBase::Get();

wxFileName OperationEditor = theConfig->Read("Tools/CodeEdit");
wxString lineOption = theConfig->Read("Tools/CodeEdit/editLineOption");

wxString callName = OperationEditor.GetFullPath()+" \""+m_errorFile.GetFullPath()+"\"";
if (!lineOption.empty())
	callName += wxString(" ") + lineOption + " " + m_errorLine;

wxExecute(callName, wxEXEC_ASYNC);