if ( !dir.empty() )
{
	currentFile = dir;
	wxFileName aFile(currentFile);
	wxFileConfig aConfig(wxEmptyString, wxEmptyString, aFile.GetFullPath());
	myUsePanel.Load(aConfig);
	SetTitle(currentFile);
	isChanged = false;
}