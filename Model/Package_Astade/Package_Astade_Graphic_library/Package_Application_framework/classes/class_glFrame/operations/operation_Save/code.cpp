//~~ void Save() [glFrame] ~~

wxFileName aFile(currentFile);

if (!aFile.IsOk() || aFile.IsDir())
{
	SaveAs();
	return;
}

wxFileConfig aConfig(wxEmptyString, wxEmptyString, aFile.GetFullPath(),
	wxEmptyString, wxCONFIG_USE_LOCAL_FILE | wxCONFIG_USE_RELATIVE_PATH);


aConfig.SetPath(wxS("/"));
aConfig.Write(wxS("Filetype"), wxS("Saved file from Astade graphic library (http://www.astade.de/)"));
aConfig.Write(wxS("SaveFileVersion"), 2);

aConfig.Write(wxS("Window/XSize"), xPixelSlider->GetValue());
aConfig.Write(wxS("Window/YSize"), yPixelSlider->GetValue());

graphicPanel->Save(aConfig);

isChanged = false;
SetTitle(currentFile);
