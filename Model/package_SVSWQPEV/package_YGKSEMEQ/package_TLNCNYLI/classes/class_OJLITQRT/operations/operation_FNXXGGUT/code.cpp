if ((m_errorFile.GetExt()!="cpp") || (!m_errorFile.FileExists()))
	return false;

wxTextFile aTextFile(m_errorFile.GetFullPath());
aTextFile.Open();

long int lineSearch = 0;
int count = 1;

m_errorLine.ToLong(&lineSearch);

while (lineSearch > 1)
{
	wxString theLine = aTextFile[lineSearch];
	if (theLine.Find("//[EOF]")==0)
		return false;

	long int end;

	if ((theLine.Find("//[")==0) && ((end=theLine.Find("]"))>3))
	{
		wxConfigBase* theConfig = wxConfigBase::Get();
		wxString ModelPath = theConfig->Read("TreeView/ModelPath");
		m_modelFile = theLine.Mid(3,end-3);
		m_modelFile.Normalize(wxPATH_NORM_ALL,ModelPath);
		m_modelLine = count;
		return true;
	}

	lineSearch--;
	count++;
}

return false;