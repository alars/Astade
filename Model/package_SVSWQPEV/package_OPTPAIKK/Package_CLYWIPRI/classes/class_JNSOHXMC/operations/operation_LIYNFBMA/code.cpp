wxString cmd = "svn add \"" + fileName.GetFullPath(wxPATH_UNIX) + "\"";
theOutput.Add(cmd);
long retVal = wxExecute(cmd, theOutput);
return (retVal) ? -1 : 0;
