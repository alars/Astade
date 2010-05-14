theOutput.Clear();
unsigned long retVal = 0;
if (fileName.FileExists())
{
	/* delete the file */
	if (wxRemoveFile(fileName.GetFullPath()))
	{
		theOutput.Add(wxS("remove file ") + fileName.GetFullPath() + wxS(" successful."));
		retVal = 0;
	}
	else
	{
		retVal = wxSysErrorCode();
		theOutput.Add(wxS("remove file ") + fileName.GetFullPath() + wxS(" failed."));
		wxString aString;
		aString.Printf(wxS("Error Code = %lu, %s"), retVal, wxSysErrorMsg(retVal));
		theOutput.Add(aString);
	}
}
else if (fileName.DirExists())
{
	/* delete all contents */
	wxDir thisDir(fileName.GetFullPath());
	wxString aFileName;
	wxFileName j;
	for (bool i = thisDir.GetFirst(&aFileName,wxEmptyString, wxDIR_FILES | wxDIR_DIRS ); i; i = thisDir.GetNext(&aFileName))
	{
		j.Clear();
		j.Assign(fileName.GetFullPath(), aFileName);
		Delete(j);
	}
	/* remove the dir itself */
	if (wxRmdir(fileName.GetFullPath()))
	{
		theOutput.Add(wxS("remove dir ") + fileName.GetFullPath() + wxS(" successful."));
		retVal = 0;
	}
	else
	{
		retVal = wxSysErrorCode();
		theOutput.Add(wxS("remove dir ") + fileName.GetFullPath() + wxS(" failed."));
		wxString aString;
		aString.Printf(wxS("Error Code = %lu, %s"), retVal, wxSysErrorMsg(retVal));
		theOutput.Add(aString);
	}
}
return retVal;
