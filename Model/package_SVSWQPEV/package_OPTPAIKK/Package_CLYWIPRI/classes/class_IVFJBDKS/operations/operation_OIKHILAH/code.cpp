wxFileName file(fileName);
file.MakeRelativeTo();
wxString cmd = "cg-add \"" + file.GetFullPath(wxPATH_UNIX) + "\"";
theOutput.Add(cmd);
int retVal = wxExecute(cmd, theOutput);
return (retVal != -1 && retVal != 0) ? 0 : 1;

