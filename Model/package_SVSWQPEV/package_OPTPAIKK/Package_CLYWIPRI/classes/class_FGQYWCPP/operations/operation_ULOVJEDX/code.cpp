int retVal = -1;
retVal = wxRenameFile(fromFileName.GetFullPath(), toFileName.GetFullPath()) ? 0 : -1;
wxString done = (retVal == 0) ? "successful" : "failed";
theOutput.Add("move " + fromFileName.GetFullPath() + " to " + toFileName.GetFullPath() + " " + done + ".");
return retVal;
