//~~ int Delete(const wxFileName& fileName) [AdeRevisionControlCVS] ~~
theOutput.Clear();

wxFileName relFileName(fileName);
relFileName.MakeRelativeTo(); // make relative to current directory

wxString cmd = wxS("cvs delete -Rf \"") + relFileName.GetFullPath(wxPATH_UNIX) + wxS("\"");
return wxExecute(cmd, theOutput);
