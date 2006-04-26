wxString cmd = "svn add \""+fileName.GetFullPath()+"\"";
theOutput.Add(cmd);
long retVal = wxExecute(cmd, theOutput);
return (retVal)? -1 : 0;