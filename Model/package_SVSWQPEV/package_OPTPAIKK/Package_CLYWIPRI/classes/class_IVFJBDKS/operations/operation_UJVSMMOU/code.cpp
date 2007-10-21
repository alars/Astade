wxFileName file(fileName);
file.MakeRelativeTo();
wxString cmd = "cg-rm -f -r \"" + file.GetFullPath(wxPATH_UNIX) + "\"";
theOutput.Add(cmd);
long retVal = wxExecute(cmd, theOutput, wxEXEC_SYNC);
return retVal;
