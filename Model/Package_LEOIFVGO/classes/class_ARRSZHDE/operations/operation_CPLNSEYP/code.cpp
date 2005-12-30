wxImage image = bitMap.ConvertToImage();

wxString savefilename = wxFileSelector( wxT("Save Image"),
                                        wxEmptyString,
                                        wxEmptyString,
                                        (const wxChar *)NULL,
                                        wxT("PNG files (*.png)|*.png|")
                                        wxT("BMP files (*.bmp)|*.bmp|")
                                        wxT("JPEG files (*.jpg)|*.jpg"),
                                        wxSAVE,
                                        this);

if ( savefilename.empty() )
    return;

wxString extension;
wxFileName::SplitPath(savefilename, NULL, NULL, &extension);

bool saved = false;
/*
if ( extension == _T("png") )
{
    static const int pngvalues[] =
    {
        wxPNG_TYPE_COLOUR,
        wxPNG_TYPE_COLOUR,
        wxPNG_TYPE_GREY,
        wxPNG_TYPE_GREY,
        wxPNG_TYPE_GREY_RED,
        wxPNG_TYPE_GREY_RED,
    };

    const wxString pngchoices[] =
    {
        _T("Colour 8bpp"),
        _T("Colour 16bpp"),
        _T("Grey 8bpp"),
        _T("Grey 16bpp"),
        _T("Grey red 8bpp"),
        _T("Grey red 16bpp"),
    };

    int sel = wxGetSingleChoiceIndex(_T("Set PNG format"),
                                     _T("Save file"),
                                     WXSIZEOF(pngchoices),
                                     pngchoices,
                                     this);
    if ( sel != -1 )
    {
        image.SetOption(wxIMAGE_OPTION_PNG_FORMAT, pngvalues[sel]);
        image.SetOption(wxIMAGE_OPTION_PNG_BITDEPTH, sel % 2 ? 16 : 8);
    }
}
*/
if ( !saved )
{
    // This one guesses image format from filename extension
    // (it may fail if the extension is not recognized):
    image.SaveFile(savefilename);
}