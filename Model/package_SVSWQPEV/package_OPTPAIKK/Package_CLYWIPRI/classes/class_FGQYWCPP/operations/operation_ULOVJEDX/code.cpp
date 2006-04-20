int retVal = -1;
retVal = wxRenameFile(fromFileName.GetFullPath(), toFileName.GetFullPath())? 0 : -1;
return retVal;