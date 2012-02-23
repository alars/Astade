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

if (timestamp.size() > 3)
{
    timestamp.Remove(0, 2);
    timestamp.RemoveLast();
    int search = eventNumber;
    wxString time;

    while ((search > 1) && ((time.size() < 3) || (time[1] != '!')))
        time = dataBase->GetTimestamp(--search);
    
    if (search > 1)
    {
        cairo_move_to(cr, 10, yPixel);
        int yPixel2 = dataBase->GetTime2Y(search) - 5;
        cairo_line_to (cr, 10, yPixel2);
        
        cairo_move_to(cr, 10, yPixel);
        cairo_line_to (cr, 8, yPixel-3);
        cairo_line_to (cr, 12, yPixel-3);
        cairo_close_path(cr);
        cairo_fill_preserve(cr);
        cairo_set_line_join (cr, CAIRO_LINE_JOIN_ROUND);
        
        cairo_move_to(cr, 10, yPixel2);
        cairo_line_to (cr, 8, yPixel2+3);
        cairo_line_to (cr, 12, yPixel2+3);
        cairo_close_path(cr);
        cairo_fill_preserve(cr);
        cairo_set_line_join (cr, CAIRO_LINE_JOIN_ROUND);
        
        cairo_move_to(cr, 14, 0.5*(yPixel - yPixel2) + yPixel2 + 3);
        cairo_show_text(cr, timestamp.utf8_str());

    }
}

cairo_stroke (cr);