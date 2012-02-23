//~~ void DrawTimeLine(cairo_t* cr, int classIndex, int eventNumber) [SeqGraphTab] ~~
wxString timestamp = dataBase->GetTimestamp(eventNumber);

if (timestamp.size() < 3)
    return;
    
if (timestamp[1] != '!')
    return;

int yPixel = dataBase->GetTime2Y(eventNumber) - 5;

setColor(cr, black);
cairo_set_line_width (cr, 0.4);
cairo_move_to(cr, GetLeftSide(classIndex), yPixel);
cairo_line_to (cr, 0, yPixel);
cairo_stroke (cr);
