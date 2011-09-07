//~~ void DrawCross(cairo_t* cr, wxDC& dc, int x, int y, const wxString& color) [SeqGraphTab] ~~
setColor(cr, green);
cairo_set_line_width (cr, 1.5);
cairo_move_to(cr, x+8, y+8);
cairo_line_to (cr, x-8, y-8);
cairo_move_to(cr, x+8, y-8);
cairo_line_to (cr, x-8, y+8);
cairo_stroke (cr);
