wxFileName aFile(currentFile);

if (!aFile.IsOk())
{
	SaveAs();
	return;
}

wxFileConfig aConfig(wxEmptyString, wxEmptyString, aFile.GetFullPath(),
	wxEmptyString, wxCONFIG_USE_LOCAL_FILE | wxCONFIG_USE_RELATIVE_PATH);


aConfig.SetPath("/");
aConfig.Write("Filetype","Saved file from Astade graphic library (http://astade.tigris.org)");
aConfig.Write("SaveFileVersion",2);

aConfig.Write("Window/XSize",xPixelSlider->GetValue());
aConfig.Write("Window/YSize",yPixelSlider->GetValue());

graphicPanel->Save(aConfig);

isChanged = false;
SetTitle(currentFile);
