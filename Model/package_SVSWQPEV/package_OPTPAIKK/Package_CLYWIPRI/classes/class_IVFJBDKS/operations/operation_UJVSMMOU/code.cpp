wxFileName file(fileName);
file.MakeRelativeTo();
wxString cmd = "cg-rm -f -r \"" + file.GetFullPath(wxPATH_UNIX) + "\"";
theOutput.Add(cmd);
int retVal = wxExecute(cmd, theOutput, wxEXEC_SYNC);
if (file.FileExists())
	wxRemoveFile(fileName.GetFullPath());
return retVal;
