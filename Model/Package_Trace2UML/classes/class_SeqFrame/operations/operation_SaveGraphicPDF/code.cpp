//~~ void SaveGraphicPDF(wxCommandEvent& event) [SeqFrame] ~~

wxString savefilename = wxFileSelector( wxS("Save Image"),
                                        wxEmptyString,
                                        wxEmptyString,
                                        wxEmptyString,
                                        wxS("PDF files (*.pdf)|*.pdf|"),
                                        wxFD_SAVE,
                                        this);

if (savefilename.empty())
    return;

cairo_surface_t* cairo_surface = cairo_pdf_surface_create(savefilename.utf8_str(), dataBase->GetGraphWidth(), dataBase->GetGraphHeight());
cairo_t* cr = cairo_create(cairo_surface);

cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);
cairo_rectangle(cr, 0.0, 0.0, dataBase->GetGraphWidth(), dataBase->GetGraphHeight());
cairo_fill(cr);
cairo_translate(cr, 0.5 , 0.5);

graphTab->DrawOnCr(cr, false);
cairo_destroy(cr);
cairo_surface_destroy(cairo_surface);
