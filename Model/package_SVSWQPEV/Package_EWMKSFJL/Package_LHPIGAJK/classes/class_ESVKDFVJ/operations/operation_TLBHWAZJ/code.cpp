if (!fileName.empty())
{
	currentFile = fileName;
	wxFileName aFile(currentFile);
	wxFileConfig aConfig(wxEmptyString, wxEmptyString, aFile.GetFullPath(),	wxEmptyString, wxCONFIG_USE_LOCAL_FILE | wxCONFIG_USE_RELATIVE_PATH);
		
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
