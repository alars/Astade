//~~ void Load(const wxString fileName) [glFrame] ~~
if (!fileName.empty())
{
	currentFile = fileName;
	wxFileName aFile(currentFile);
	wxFileConfig aConfig(wxEmptyString, wxEmptyString, aFile.GetFullPath(),	wxEmptyString, wxCONFIG_USE_LOCAL_FILE | wxCONFIG_USE_RELATIVE_PATH);
		
    int saveVersion = 1;
    bool read = aConfig.Read("SaveFileVersion",&saveVersion);
    
    if (read && (saveVersion < 2))
    {
         wxMessageBox("This file has an older graphic format. If you overwrite it with this, newer program, the program which has generated this file will not be able to read it any more!", "Notice!", wxOK | wxICON_INFORMATION , this);
    }

	int w = 600;
	aConfig.Read("Window/XSize",&w);

	int h = 400;
	aConfig.Read("Window/YSize",&h);

	xPixelSlider->SetValue(w);
	yPixelSlider->SetValue(h);
	wxScrollEvent dummy;
	OnSliderMove(dummy);
		
	graphicPanel->Load(aConfig);
	SetTitle(currentFile);
	isChanged = false;
}
