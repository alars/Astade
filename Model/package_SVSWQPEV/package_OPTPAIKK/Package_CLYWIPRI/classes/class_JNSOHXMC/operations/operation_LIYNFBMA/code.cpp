wxString cmd = "svn add "+fileName.GetFullPath();
long retVal = wxExecute(cmd, wxEXEC_SYNC);
return (retVal)? -1 : 0;