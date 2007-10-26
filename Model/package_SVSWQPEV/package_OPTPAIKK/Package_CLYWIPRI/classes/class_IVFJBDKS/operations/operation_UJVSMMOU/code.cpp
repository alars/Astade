wxFileName file(fileName);
file.MakeRelativeTo();
wxString cmd = "cg-rm -f -r \"" + file.GetFullPath(wxPATH_UNIX) + "\"";
theOutput.Add(cmd);
return wxExecute(cmd, theOutput, wxEXEC_SYNC);
