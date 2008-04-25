theOutput.Clear();
wxFileName file(fileName);
file.MakeRelativeTo();
wxString cmd = "git-add \"" + file.GetFullPath(wxPATH_UNIX) + "\"";
theOutput.Add(cmd);
return wxExecute(cmd, theOutput);
