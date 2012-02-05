//~~ void DrawComment(cairo_t* cr, const wxString& text, int timeIndex) [SeqGraphTab] ~~

setColor(cr, purple);
cairo_set_line_width(cr, 1);
cairo_move_to(cr, 0, dataBase->GetTime2Y(timeIndex) - 14);
cairo_line_to(cr, dataBase->GetGraphWidth(), dataBase->GetTime2Y(timeIndex) - 14);
cairo_stroke(cr);

setColor(cr, black);
cairo_move_to(cr, 2, dataBase->GetTime2Y(timeIndex) - 2);
cairo_show_text(cr, text.utf8_str());
