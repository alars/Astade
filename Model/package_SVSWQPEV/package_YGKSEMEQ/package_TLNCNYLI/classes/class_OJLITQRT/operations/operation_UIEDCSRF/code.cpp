wxConfigBase* theConfig = wxConfigBase::Get();

wxRegEx identifyRegEx(theConfig->Read("TreeView/RegEx/identifyExpression"));
wxRegEx errorLineRegEx(theConfig->Read("TreeView/RegEx/errorLineExpression"));
wxRegEx errorFileRegEx(theConfig->Read("TreeView/RegEx/errorFileExpression"));

if (!identifyRegEx.IsValid() || !errorLineRegEx.IsValid() || !errorFileRegEx.IsValid())
	return false;


if (identifyRegEx.Matches(parseLine) && errorLineRegEx.Matches(parseLine) && errorFileRegEx.Matches(parseLine))
{
	m_errorFile = errorFileRegEx.GetMatch(parseLine,1);
	m_errorLine = errorLineRegEx.GetMatch(parseLine,1);
	m_errorFile.Normalize(wxPATH_NORM_ALL,activeConfiguration.GetPath());
	//wxLogMessage("detected error in file \"%s\" line \"%s\"",m_errorFile.GetFullPath().c_str(),m_errorLine.c_str());
	return true;
}
else
	return false;