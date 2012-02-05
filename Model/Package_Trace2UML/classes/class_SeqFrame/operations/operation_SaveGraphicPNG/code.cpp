//~~ void SaveGraphicPNG(wxCommandEvent& event) [SeqFrame] ~~
wxString savefilename = wxFileSelector( wxS("Save Image"),
                                        wxEmptyString,
                                        wxEmptyString,
                                        wxEmptyString,
                                        wxS("PNG files (*.png)|*.png|"),
#if wxCHECK_VERSION(2,8,0)
                                        wxFD_SAVE,
#else
                                        wxSAVE,
#endif
                                        this);

if (savefilename.empty())
    return;

cairo_surface_t* cairo_surface = cairo_image_surface_create(CAIRO_FORMAT_RGB24, dataBase->GetGraphWidth(), dataBase->GetGraphHeight());
cairo_t* cr = cairo_create(cairo_surface);

cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);
cairo_rectangle(cr, 0.0, 0.0, dataBase->GetGraphWidth(), dataBase->GetGraphHeight());
cairo_fill(cr);
cairo_translate(cr, 0.5 , 0.5);

graphTab->DrawOnCr(cr, false);
cairo_surface_write_to_png (cairo_surface, savefilename.utf8_str());
cairo_destroy(cr);
cairo_surface_destroy(cairo_surface);
