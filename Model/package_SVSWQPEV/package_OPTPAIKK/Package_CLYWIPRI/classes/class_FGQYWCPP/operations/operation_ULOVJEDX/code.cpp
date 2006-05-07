int retVal = -1;
retVal = wxRenameFile(fromFileName.GetFullPath(), toFileName.GetFullPath()) ? 0 : -1;

if (wxRenameFile(fromFileName.GetFullPath(), toFileName.GetFullPath()))
{
	theOutput.Add("move " + fromFileName.GetFullPath() + " to " + toFileName.GetFullPath() + " successful.");
	retVal = 0;
}
else
{
	retVal = wxSysErrorCode();
	theOutput.Add("move " + fromFileName.GetFullPath() + " to " + toFileName.GetFullPath() + " failed.");
	wxString aString;
	aString.Printf("Error Code = %d, %s",retVal,wxSysErrorMsg(retVal));
	theOutput.Add(aString);
}

return retVal;
