/*
	svn delete complains the deletion of files with local changes
	--force overwrites this and deletes everething w/o warnings
*/
wxString cmd = "svn delete --force \"" + fileName.GetFullPath(wxPATH_UNIX) + "\"";
return wxExecute(cmd, theOutput, wxEXEC_SYNC);
