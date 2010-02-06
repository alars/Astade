Drop(fromFileName);

unsigned long retVal = 0;
if (wxRenameFile(fromFileName.GetFullPath(), toFileName.GetFullPath()))
{
	theOutput.Add("move " + fromFileName.GetFullPath() + " to " + toFileName.GetFullPath() + " successful.");
	retVal = 0;
	Add(toFileName);
}
else
{
	retVal = wxSysErrorCode();
	theOutput.Add("move " + fromFileName.GetFullPath() + " to " + toFileName.GetFullPath() + " failed.");
	wxString aString;
	aString.Printf("Error Code = %lu, %s", retVal, wxSysErrorMsg(retVal));
	theOutput.Add(aString);
	Add(fromFileName);
}
return retVal;
