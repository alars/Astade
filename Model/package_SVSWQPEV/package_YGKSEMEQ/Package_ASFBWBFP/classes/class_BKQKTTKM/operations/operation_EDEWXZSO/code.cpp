/* vi: set tabstop=4: */

if (!dir.empty())
{
	currentFile = dir;
	wxFileName aFile(currentFile);
	wxFileConfig aConfig(wxEmptyString, wxEmptyString, aFile.GetFullPath(),
		wxEmptyString, wxCONFIG_USE_LOCAL_FILE | wxCONFIG_USE_RELATIVE_PATH);
	myUsePanel.Load(aConfig);
	SetTitle(currentFile);
	isChanged = false;
}
