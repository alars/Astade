if (fileName.FileExists())
{
	wxString cmd = "pj add -y -P " + myProjectFile + " \"" + fileName.GetFullPath(wxPATH_UNIX) + "\"";
	theOutput.Add(cmd);
	long retVal = wxExecute(cmd, theOutput);
	return (retVal != -1 && retVal != 0) ? 0 : 1;
}
else if (fileName.DirExists())
{
	wxDir thisDir(fileName.GetFullPath());
	wxString aFileName;
	wxFileName j;
	for (bool i = thisDir.GetFirst(&aFileName,wxEmptyString, wxDIR_FILES | wxDIR_DIRS ); i; i = thisDir.GetNext(&aFileName))
	{
		j.Clear();
		j.Assign(fileName.GetFullPath(), aFileName);
		Add(j);
	}
}
return -1;
