wxImage image(bitMap.ConvertToImage());

wxString savefilename = wxFileSelector( _T("Save Image"),
                                        wxEmptyString,
                                        wxEmptyString,
                                        (const wxChar *)NULL,
                                        _T("PNG files (*.png)|*.png|")
                                        _T("BMP files (*.bmp)|*.bmp|")
                                        _T("JPEG files (*.jpg)|*.jpg"),
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
