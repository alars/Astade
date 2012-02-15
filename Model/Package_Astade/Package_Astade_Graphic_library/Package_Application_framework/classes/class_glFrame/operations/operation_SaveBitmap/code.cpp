//~~ void SaveBitmap(const wxBitmap& bitMap) [glFrame] ~~

wxImage image(bitMap.ConvertToImage());

wxString savefilename = wxFileSelector( wxS("Save Image"),
                                        wxEmptyString,
                                        wxEmptyString,
                                        wxEmptyString,
                                        wxS("PNG files (*.png)|*.png|")
                                        wxS("BMP files (*.bmp)|*.bmp|")
                                        wxS("JPEG files (*.jpg)|*.jpg"),
                                        wxFD_SAVE,
                                        this);

if (savefilename.empty())
    return;

// This one guesses image format from filename extension
// (it may fail if the extension is not recognized):
image.SaveFile(savefilename);
