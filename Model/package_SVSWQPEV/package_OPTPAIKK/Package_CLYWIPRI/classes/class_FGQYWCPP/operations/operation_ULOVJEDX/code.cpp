int retVal = -1;
retVal = wxRenameFile(fromFileName.GetFullPath(), toFileName.GetFullPath())? 0 : -1;
wxString done = (retVal==0)? "successfull" : "failed";
theOutput.Add("move "+fromFileName.GetFullPath()+" to "+toFileName.GetFullPath()+" "+done+ ".\n");
return retVal;