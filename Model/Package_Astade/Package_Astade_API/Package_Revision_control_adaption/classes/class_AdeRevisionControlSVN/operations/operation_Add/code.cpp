//~~ int Add(const wxFileName& fileName) [AdeRevisionControlSVN] ~~
theOutput.Clear();
wxString cmd = wxS("svn add \"") + fileName.GetFullPath(wxPATH_UNIX) + wxS("\"");
theOutput.Add(cmd);
return wxExecute(cmd, theOutput);
