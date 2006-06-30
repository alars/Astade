wxString cmd = "cg-rm -f -r \"" + fileName.GetFullPath(wxPATH_UNIX) + "\"";
theOutput.Add(cmd);
long retVal = wxExecute(cmd, theOutput, wxEXEC_SYNC);
return retVal;
