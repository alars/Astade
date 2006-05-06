wxString cmd = "svn delete \""+fileName.GetFullPath()+"\"";
int retVal = wxExecute(cmd, theOutput, wxEXEC_SYNC);
return retVal;
