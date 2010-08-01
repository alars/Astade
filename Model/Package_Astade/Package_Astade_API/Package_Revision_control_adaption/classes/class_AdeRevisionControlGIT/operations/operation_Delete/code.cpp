//~~ int Delete(const wxFileName& fileName) [AdeRevisionControlGIT] ~~

theOutput.Clear();
wxFileName file(fileName);
file.MakeRelativeTo();
wxString cmd = wxS("git rm -f -r \"") + file.GetFullPath(wxPATH_UNIX) + wxS("\"");
theOutput.Add(cmd);
int retVal = wxExecute(cmd, theOutput);
if (file.FileExists())
	wxRemoveFile(fileName.GetFullPath());
return retVal;
