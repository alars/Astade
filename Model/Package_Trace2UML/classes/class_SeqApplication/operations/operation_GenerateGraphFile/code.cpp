//~~ void GenerateGraphFile(const wxString& inFile, const wxString& outFile) [SeqApplication] ~~

wxTextFile aTextFile(inFile);
SeqDataBase aDataBase(0);

if (aTextFile.Exists())
{
    aTextFile.Open();

    if (aTextFile.IsOpened())
    {
        wxString str;
        aDataBase.Clear();
        for ( str = aTextFile.GetFirstLine(); !aTextFile.Eof(); str = aTextFile.GetNextLine() )
            aDataBase.AddLine(str);
            
        aDataBase.AddLine(str);
        
        SeqGraphTab aGraphTab(0, &aDataBase);

         // First Round is, to find out the needed size
        cairo_surface_t* cairo_surface = cairo_image_surface_create(CAIRO_FORMAT_RGB24, 100, 100);
        cairo_t* cr = cairo_create(cairo_surface);
        aGraphTab.DrawOnCr(cr, false);
        cairo_destroy(cr);
        cairo_surface_destroy(cairo_surface);

        cairo_surface = cairo_image_surface_create(CAIRO_FORMAT_RGB24, aDataBase.GetGraphWidth(), aDataBase.GetGraphHeight());
        cr = cairo_create(cairo_surface);

        cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);
        cairo_rectangle(cr, 0.0, 0.0, aDataBase.GetGraphWidth(), aDataBase.GetGraphHeight());
        cairo_fill(cr);
        cairo_translate(cr, 0.5 , 0.5);

        aGraphTab.DrawOnCr(cr, false);
        cairo_surface_write_to_png (cairo_surface, outFile.utf8_str());
        cairo_destroy(cr);
        cairo_surface_destroy(cairo_surface);
    }
}
