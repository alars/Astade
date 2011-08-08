//~~ void DrawStatechange(cairo_t* cr, wxString text, int eventNumber) [SeqGraphTab] ~~

int start = dataBase->GetSourceIndex(eventNumber);
int yPixel = dataBase->GetTime2Y(eventNumber)-6;
int xPixel = dataBase->GetClassMiddle(start);
int radius = 4;

cairo_text_extents_t theExtents;
cairo_text_extents(cr, text.c_str(), &theExtents);

double halfwidth = (theExtents.width + 4)/2;
    
if (halfwidth < 30)
    halfwidth = 30;

cairo_set_source_rgb(cr, 1.0, 1.0, 0.6);
cairo_move_to(cr, xPixel-halfwidth, yPixel-radius+3);
cairo_arc(cr, xPixel-halfwidth+radius, yPixel+radius-11, radius, 1.0 * M_PI, 1.5 * M_PI);
cairo_arc(cr, xPixel+halfwidth-radius, yPixel+radius-11, radius, 1.5 * M_PI, 2.0 * M_PI);
cairo_arc(cr, xPixel+halfwidth-radius, yPixel-radius+3, radius, 0.0 * M_PI, 0.5 * M_PI);
cairo_arc(cr, xPixel-halfwidth+radius, yPixel-radius+3, radius, 0.5 * M_PI, 1.0 * M_PI);
cairo_close_path (cr);
cairo_fill_preserve(cr);
setColor(cr, blue);
cairo_stroke (cr);

setColor(cr, black);

cairo_move_to(cr, xPixel-(theExtents.width / 2), yPixel-1.0);
cairo_show_text(cr, text.c_str());
