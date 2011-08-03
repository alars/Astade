//~~ void SaveBitmap(const wxBitmap& bitMap) [SeqFrame] ~~
wxImage image(bitMap.ConvertToImage());

wxString savefilename = wxFileSelector( wxS("Save Image"),
                                        wxEmptyString,
                                        wxEmptyString,
                                        wxEmptyString,
                                        wxS("PNG files (*.png)|*.png|")
                                        wxS("BMP files (*.bmp)|*.bmp|")
                                        wxS("JPEG files (*.jpg)|*.jpg"),
#if wxCHECK_VERSION(2,8,0)
                                        wxFD_SAVE,
#else
                                        wxSAVE,
#endif
                                        this);

if (savefilename.empty())
    return;

// This one guesses image format from filename extension
// (it may fail if the extension is not recognized):
image.SaveFile(savefilename);
