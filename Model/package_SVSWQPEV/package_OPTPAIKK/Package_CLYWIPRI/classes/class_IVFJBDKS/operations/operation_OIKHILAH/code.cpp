wxFileName file(fileName);
file.MakeRelativeTo();
wxString cmd = "cg-add -r \"" + file.GetFullPath(wxPATH_UNIX) + "\"";
theOutput.Add(cmd);
return wxExecute(cmd, theOutput, wxEXEC_SYNC);
