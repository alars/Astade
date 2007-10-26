wxString cmd = "svn add \"" + fileName.GetFullPath(wxPATH_UNIX) + "\"";
theOutput.Add(cmd);
return wxExecute(cmd, theOutput);
