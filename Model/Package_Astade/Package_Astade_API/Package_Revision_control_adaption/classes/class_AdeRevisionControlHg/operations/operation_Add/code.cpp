//~~ int Add(const wxFileName& fileName) [AdeRevisionControlHg] ~~

theOutput.Clear();
wxFileName file(fileName);
file.MakeRelativeTo();
wxString cmd = wxS("hg add \"") + file.GetFullPath(wxPATH_UNIX) + wxS("\"");
theOutput.Add(cmd);
return wxExecute(cmd, theOutput);
