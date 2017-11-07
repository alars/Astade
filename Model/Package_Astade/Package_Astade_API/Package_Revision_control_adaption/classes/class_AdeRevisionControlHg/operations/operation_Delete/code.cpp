//~~ int Delete(const wxFileName& fileName) [AdeRevisionControlHg] ~~

theOutput.Clear();
wxFileName file(fileName);
file.MakeRelativeTo();
wxString cmd = wxS("hg remove -f -S \"") + file.GetFullPath(wxPATH_UNIX) + wxS("\"");
theOutput.Add(cmd);
int retVal = wxExecute(cmd, theOutput);
if (file.FileExists())
	wxRemoveFile(fileName.GetFullPath());
return retVal;
