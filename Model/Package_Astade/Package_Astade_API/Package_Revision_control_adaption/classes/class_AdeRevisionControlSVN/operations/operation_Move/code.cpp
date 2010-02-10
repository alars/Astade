theOutput.Clear();
wxString cmd = "svn move --force \"" + fromFileName.GetFullPath(wxPATH_UNIX) + "\" \"" + toFileName.GetFullPath(wxPATH_UNIX) + "\"";
return wxExecute(cmd, theOutput);
