//~~ void DrawNote(cairo_t* cr, wxString text, int eventNumber) [SeqGraphTab] ~~
int start = dataBase->GetSourceIndex(eventNumber);
int yPixel = dataBase->GetTime2Y(eventNumber);
int xPixel = dataBase->GetClassMiddle(start);
int hight = dataBase->GetTime2Y(eventNumber) - dataBase->GetTime2Y(eventNumber-1) - 2;

setColor(cr, white);
cairo_set_line_width (cr, 0.8);
cairo_move_to(cr, xPixel-30, yPixel);
cairo_rel_line_to(cr, 0, -hight+6);
cairo_rel_line_to(cr, 10, -6);
cairo_rel_line_to(cr, 90-10, 0);
cairo_rel_line_to(cr, 0, hight);
cairo_close_path(cr);
cairo_fill_preserve(cr);

cairo_set_source_rgb(cr, 0.4, 0.4, 0.4);
cairo_stroke (cr);

cairo_set_source_rgb(cr, 0.8, 0.8, 0.8);
cairo_move_to(cr, xPixel-30+10, yPixel-hight);
cairo_rel_line_to(cr, 0, 6);
cairo_rel_line_to(cr, -10, 0);
cairo_close_path(cr);
cairo_fill_preserve(cr);
cairo_set_source_rgb(cr, 0.4, 0.4, 0.4);
cairo_stroke (cr);

wxString lineText;
int line = 0;

text += " ";

do
{
    lineText = text;
    cairo_text_extents_t theExtents;
    setColor(cr, black);

    do
    {
        cairo_text_extents(cr, lineText.c_str(), &theExtents);
        if (theExtents.width > 85)
            lineText.RemoveLast();
    } while (theExtents.width > 85);

    while ((lineText.Find(' ') != wxNOT_FOUND || lineText.Find('-') != wxNOT_FOUND) &&
           lineText.Last() != ' ' && lineText.Last() != '-')
           lineText.RemoveLast();

    cairo_move_to(cr, xPixel-28, (11.5*line) + yPixel-hight+15);
    cairo_show_text(cr, lineText.c_str());
    
    text.Remove(0,lineText.size());
    line++;
} while (line < 6 && !text.empty());
