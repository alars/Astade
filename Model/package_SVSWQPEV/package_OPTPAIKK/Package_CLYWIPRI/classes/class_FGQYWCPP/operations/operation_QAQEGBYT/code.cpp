int retVal = -1;
if (fileName.FileExists()) {
	/* delete the file */
	retVal = wxRemoveFile(fileName.GetFullPath()) ? 0 : -1;
	wxString done = (retVal == 0) ? "successful" : "failed";
	theOutput.Add("remove file " + fileName.GetFullPath() + " " + done + ".");
} else if (fileName.DirExists()) {
	/* delete all contents */
	wxDir thisDir(fileName.GetFullPath());
	wxString aFileName;
	wxFileName j;
	for (bool i = thisDir.GetFirst(&aFileName); i; i = thisDir.GetNext(&aFileName)) {
		j.Clear();
		j.Assign(fileName.GetFullPath(), aFileName);
		Delete(j);
	}
	/* remove the dir itself */
	retVal = wxRmdir(fileName.GetFullPath()) ? 0 : -1;
	wxString done = (retVal == 0) ? "successful" : "failed";
	theOutput.Add("remove dir " + fileName.GetFullPath() + " " + done + ".");
}
return retVal;
