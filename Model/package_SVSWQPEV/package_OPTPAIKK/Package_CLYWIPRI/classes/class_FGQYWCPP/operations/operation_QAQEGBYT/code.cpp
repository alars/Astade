unsigned long retVal = 0;
if (fileName.FileExists())
{
	/* delete the file */
	if (wxRemoveFile(fileName.GetFullPath()))
	{
		theOutput.Add("remove file " + fileName.GetFullPath() + " successful.");
		retVal = 0;
	}
	else
	{
		retVal = wxSysErrorCode();
		theOutput.Add("remove file " + fileName.GetFullPath() + " failed.");
		wxString aString;
		aString.Printf("Error Code = %lu, %s", retVal, wxSysErrorMsg(retVal));
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
		theOutput.Add("remove dir " + fileName.GetFullPath() + " successful.");
		retVal = 0;
	}
	else
	{
		retVal = wxSysErrorCode();
		theOutput.Add("remove dir " + fileName.GetFullPath() + " failed.");
		wxString aString;
		aString.Printf("Error Code = %lu, %s", retVal, wxSysErrorMsg(retVal));
		theOutput.Add(aString);
	}
}
return retVal;
