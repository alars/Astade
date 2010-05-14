theOutput.Clear();
/*
	svn delete complains the deletion of files with local changes
	--force overwrites this and deletes everething w/o warnings
*/
wxString cmd = wxS("svn delete --force \"") + fileName.GetFullPath(wxPATH_UNIX) + wxS("\"");
return wxExecute(cmd, theOutput);
