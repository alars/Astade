wxFileName aFile(currentFile);

if (aFile.GetExt() != "ucm")
{
	SaveFileAs(event);
	return;
}

wxFileConfig aConfig(wxEmptyString, wxEmptyString, aFile.GetFullPath());

myUsePanel.Save(aConfig);

isChanged = false;
SetTitle(currentFile);