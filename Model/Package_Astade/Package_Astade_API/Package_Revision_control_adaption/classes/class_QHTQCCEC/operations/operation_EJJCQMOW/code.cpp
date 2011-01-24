//~~ int Add(const wxFileName& fileName) [AdeRevisionControlCVS] ~~
theOutput.Clear();
wxString cmd = wxS("cvs add \"") + fileName.GetFullPath(wxPATH_UNIX) + wxS("\"");
theOutput.Add(cmd);
return wxExecute(cmd, theOutput);
