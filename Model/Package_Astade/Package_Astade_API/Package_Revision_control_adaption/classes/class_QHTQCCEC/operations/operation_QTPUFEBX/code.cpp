//~~ int Move(const wxFileName& fromFileName, const wxFileName& toFileName) [AdeRevisionControlCVS] ~~
theOutput.Clear();
wxString cmd = wxS("cvs move --force \"") + fromFileName.GetFullPath(wxPATH_UNIX) + wxS("\" \"") + toFileName.GetFullPath(wxPATH_UNIX) + wxS("\"");
return wxExecute(cmd, theOutput);
