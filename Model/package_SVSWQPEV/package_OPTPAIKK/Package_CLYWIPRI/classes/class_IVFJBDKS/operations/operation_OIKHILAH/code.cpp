wxString cmd = "cg-add -r \"" + fileName.GetFullPath(wxPATH_UNIX) + "\"";
theOutput.Add(cmd);
long retVal = wxExecute(cmd, theOutput, wxEXEC_SYNC);
return retVal;
