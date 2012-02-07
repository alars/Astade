//~~ bool ParseTextline(wxString& parseLine) [AstadeMakeOutputEdit] ~~

wxConfigBase* theConfig = wxConfigBase::Get();

wxRegEx identifyRegEx(theConfig->Read(wxS("TreeView/RegEx/identifyExpression")));
wxRegEx errorLineRegEx(theConfig->Read(wxS("TreeView/RegEx/errorLineExpression")));
wxRegEx errorFileRegEx(theConfig->Read(wxS("TreeView/RegEx/errorFileExpression")));

if (!identifyRegEx.IsValid() || !errorLineRegEx.IsValid() || !errorFileRegEx.IsValid())
	return false;


if (identifyRegEx.Matches(parseLine) && errorLineRegEx.Matches(parseLine) && errorFileRegEx.Matches(parseLine))
{
	m_errorFile = errorFileRegEx.GetMatch(parseLine, 1);
	m_errorFile.Normalize(wxPATH_NORM_ALL,activeConfiguration.GetPath());
	
	if (!m_errorFile.FileExists())
	{
		wxString nameOnly = m_errorFile.GetFullName();
		m_errorFile.Assign(nameOnly);
		m_errorFile.AppendDir(wxS(".."));
		m_errorFile.AppendDir(wxS("auto"));
		m_errorFile.Normalize(wxPATH_NORM_ALL,activeConfiguration.GetPath());
	}
	
	if (!m_errorFile.FileExists())
	{
		wxString nameOnly = m_errorFile.GetFullName();
		m_errorFile.Assign(nameOnly);
		m_errorFile.AppendDir(wxS(".."));
		m_errorFile.AppendDir(wxS("manual"));
		m_errorFile.Normalize(wxPATH_NORM_ALL,activeConfiguration.GetPath());
	}
	
	if (!m_errorFile.FileExists())
	{
		return false;
	}
		
	m_errorLine = errorLineRegEx.GetMatch(parseLine,1);
	return true;
}
else
	return false;
