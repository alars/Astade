wxString cmd = "svn move --force \"" + fromFileName.GetFullPath(wxPATH_UNIX) + "\" \"" + toFileName.GetFullPath(wxPATH_UNIX) + "\"";
long retVal = wxExecute(cmd, theOutput, wxEXEC_SYNC);
return (retVal) ? -1 : 0;
