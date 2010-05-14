Drop(fromFileName);

unsigned long retVal = 0;
if (wxRenameFile(fromFileName.GetFullPath(), toFileName.GetFullPath()))
{
	theOutput.Add(wxS("move ") + fromFileName.GetFullPath() + wxS(" to ") + toFileName.GetFullPath() + wxS(" successful."));
	retVal = 0;
	Add(toFileName);
}
else
{
	retVal = wxSysErrorCode();
	theOutput.Add(wxS("move ") + fromFileName.GetFullPath() + wxS(" to ") + toFileName.GetFullPath() + wxS(" failed."));
	wxString aString;
	aString.Printf(wxS("Error Code = %lu, %s"), retVal, wxSysErrorMsg(retVal));
	theOutput.Add(aString);
	Add(fromFileName);
}
return retVal;
