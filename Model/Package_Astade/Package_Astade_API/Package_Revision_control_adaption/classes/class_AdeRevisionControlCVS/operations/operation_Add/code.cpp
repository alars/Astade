//~~ int Add(const wxFileName& fileName) [AdeRevisionControlCVS] ~~
theOutput.Clear();

wxFileName relFileName(fileName);
relFileName.MakeRelativeTo(); // make relative to current directory

wxString cmd = wxS("cvs add \"") + relFileName.GetFullPath(wxPATH_UNIX) + wxS("\"");
theOutput.Add(cmd);

return wxExecute(cmd, theOutput);
