//~~ int Add(const wxFileName& fileName) [AdeRevisionControlGIT] ~~

theOutput.Clear();
wxFileName file(fileName);
file.MakeRelativeTo();
wxString cmd = wxS("git add \"") + file.GetFullPath(wxPATH_UNIX) + wxS("\"");
theOutput.Add(cmd);
return wxExecute(cmd, theOutput);
