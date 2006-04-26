wxString cmd = "svn del \""+fileName.GetFullPath()+"\"";
int retVal = wxExecute(cmd, theOutput, wxEXEC_SYNC);
return retVal;