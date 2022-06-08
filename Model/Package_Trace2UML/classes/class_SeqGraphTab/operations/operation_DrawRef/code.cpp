//~~ void DrawRef(cairo_t* cr, wxString text, int eventNumber) [SeqGraphTab] ~~

int start = dataBase->GetSourceIndex(eventNumber);
int yPixel = dataBase->GetTime2Y(eventNumber)-6;
int xPixel = dataBase->GetClassMiddle(start);
int radius = 4;

int pos = text.find("|");
if (pos > 0)
    text.erase(pos);

cairo_text_extents_t theExtents;
cairo_text_extents(cr, text.utf8_str(), &theExtents);

double halfwidth = (theExtents.width + 4)/2;
    
if (halfwidth < 30)
    halfwidth = 30;

cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);
cairo_move_to(cr, xPixel-halfwidth, yPixel + 10);
cairo_line_to(cr,xPixel+halfwidth, yPixel + 10);
cairo_line_to(cr,xPixel+halfwidth, yPixel - 20);
cairo_line_to(cr,xPixel-halfwidth, yPixel - 20);

cairo_close_path (cr);
cairo_fill_preserve(cr);

cairo_move_to(cr, xPixel-halfwidth, yPixel - 20 + 12);
cairo_line_to(cr, xPixel-halfwidth + 18, yPixel - 20 + 12);
cairo_line_to(cr, xPixel-halfwidth + 22, yPixel -20 + 6);
cairo_line_to(cr, xPixel-halfwidth + 22, yPixel - 20);

setColor(cr, black);
cairo_stroke (cr);

cairo_move_to(cr, xPixel - halfwidth + 2, yPixel - 11.0);
cairo_show_text(cr, "ref");

cairo_move_to(cr, xPixel - (theExtents.width / 2), yPixel + 4);
cairo_show_text(cr, text.utf8_str());
