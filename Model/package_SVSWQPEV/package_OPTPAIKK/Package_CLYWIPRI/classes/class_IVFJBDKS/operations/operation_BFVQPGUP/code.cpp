wxString cmd = "cg-mv \"" + fromFileName.GetFullPath(wxPATH_UNIX) + "\" \"" + toFileName.GetFullPath(wxPATH_UNIX) + "\"";
theOutput.Add(cmd);
long retVal = wxExecute(cmd, theOutput, wxEXEC_SYNC);
return retVal;
