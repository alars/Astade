wxFileName file(fileName);
file.MakeRelativeTo();
wxString cmd = "cg-add -r \"" + file.GetFullPath(wxPATH_UNIX) + "\"";
theOutput.Add(cmd);
long retVal = wxExecute(cmd, theOutput, wxEXEC_SYNC);
return retVal;
