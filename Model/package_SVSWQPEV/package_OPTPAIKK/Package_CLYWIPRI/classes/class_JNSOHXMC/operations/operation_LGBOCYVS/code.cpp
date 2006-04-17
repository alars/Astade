wxString cmd = "svn mv "+fromFileName.GetFullPath()+" "+toFileName.GetFullPath();
long retVal = wxExecute(cmd, *theOutput, wxEXEC_SYNC);
return (retVal)? -1 : 0;