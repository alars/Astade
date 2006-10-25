/* vi: set tabstop=4: */

wxFileName aFile(currentFile);

if (aFile.GetExt() != "ucm")
{
	SaveFileAs(event);
	return;
}

wxFileConfig aConfig(wxEmptyString, wxEmptyString, aFile.GetFullPath(),
	wxEmptyString, wxCONFIG_USE_LOCAL_FILE | wxCONFIG_USE_RELATIVE_PATH);

myUsePanel.Save(aConfig);

isChanged = false;
SetTitle(currentFile);
