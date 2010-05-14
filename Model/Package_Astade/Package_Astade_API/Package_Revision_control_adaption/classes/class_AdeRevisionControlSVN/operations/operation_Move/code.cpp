theOutput.Clear();
wxString cmd = wxS("svn move --force \"") + fromFileName.GetFullPath(wxPATH_UNIX) + wxS("\" \"") + toFileName.GetFullPath(wxPATH_UNIX) + wxS("\"");
return wxExecute(cmd, theOutput);
