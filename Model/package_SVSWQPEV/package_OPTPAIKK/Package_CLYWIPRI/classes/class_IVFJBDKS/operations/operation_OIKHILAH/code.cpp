theOutput.Clear();
wxFileName file(fileName);
file.MakeRelativeTo();
wxString cmd = "cg-add \"" + file.GetFullPath(wxPATH_UNIX) + "\"";
theOutput.Add(cmd);
return wxExecute(cmd, theOutput);
