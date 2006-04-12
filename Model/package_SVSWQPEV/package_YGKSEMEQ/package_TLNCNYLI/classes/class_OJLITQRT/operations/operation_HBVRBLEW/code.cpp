wxConfigBase* theConfig = wxConfigBase::Get();

wxFileName OperationEditor = theConfig->Read("Tools/CodeEdit");

wxString callName = OperationEditor.GetFullPath()+" \""+m_errorFile.GetFullPath()+"\"";

wxExecute(callName, wxEXEC_ASYNC);