wxImage image(bitMap.ConvertToImage());

wxString savefilename = wxFileSelector( wxT("Save Image"),
                                        wxEmptyString,
                                        wxEmptyString,
                                        (const wxChar *)NULL,
                                        wxT("PNG files (*.png)|*.png|")
                                        wxT("BMP files (*.bmp)|*.bmp|")
                                        wxT("JPEG files (*.jpg)|*.jpg"),
                                        wxSAVE,
                                        this);

if (savefilename.empty())
    return;

// This one guesses image format from filename extension
// (it may fail if the extension is not recognized):
image.SaveFile(savefilename);
