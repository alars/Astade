wxString cmd = "svn add \"" + fileName.GetFullPath(wxPATH_UNIX) + "\"";
theOutput.Add(cmd);
int retVal = wxExecute(cmd, theOutput);
return (retVal != -1 && retVal != 0) ? 0 : 1;
