/* vi: set tabstop=4: */

if (m_errorFile.GetExt() != "cpp" || !m_errorFile.FileExists())
	return false;

wxTextFile aTextFile(m_errorFile.GetFullPath());
aTextFile.Open();

long lineSearch = 0;
int count = 0;

m_errorLine.ToLong(&lineSearch);

while (--lineSearch > 0)
{
	wxString theLine = aTextFile[lineSearch];
	if (theLine.Find(_T("//[EOF]")) == 0)
		return false;

	long end;
	if (theLine.Find(_T("//[")) == 0 && (end = theLine.Find(_T("]"))) > 3)
	{
		wxConfigBase* theConfig = wxConfigBase::Get();
		wxString ModelPath = theConfig->Read("TreeView/ModelPath");
		m_modelFile = theLine.Mid(3, end - 3);
		m_modelFile.Normalize(wxPATH_NORM_ALL, ModelPath);
		m_modelLine = count;
		return true;
	}

	count++;
}

return false;
