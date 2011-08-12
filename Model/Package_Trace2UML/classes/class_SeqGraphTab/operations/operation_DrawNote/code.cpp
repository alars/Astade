//~~ void DrawNote(cairo_t* cr, wxString text, int eventNumber) [SeqGraphTab] ~~
int start = dataBase->GetSourceIndex(eventNumber);
int yPixel = dataBase->GetTime2Y(eventNumber);
int maxhight = yPixel - dataBase->GetTime2Y(eventNumber-1);
int xPixel = dataBase->GetClassMiddle(start);
int hight = maxhight - 4;

double needHight = 8;
wxString outText(text);
wxString lineText;
int line = 0;

const double edgeHight = 13;
const double edgeWidth = 13;
const double leftSide = 30;
const double rightSide = 60;
const double border = 2.5;

do
{
    lineText = (outText + " ").Left(34);
    cairo_text_extents_t theExtents;

    double maxlen;
    if (line == 0)
        maxlen = leftSide + rightSide - (2*border);
    else
        maxlen = edgeWidth + leftSide + rightSide - (2*border);
    
    do
    {
        cairo_text_extents(cr, lineText.c_str(), &theExtents);
        if (theExtents.width > maxlen)
            lineText.RemoveLast();
    } while (theExtents.width > maxlen);

    while ((lineText.Find(' ') != wxNOT_FOUND || lineText.Find('-') != wxNOT_FOUND) &&
           lineText.Last() != ' ' && lineText.Last() != '-')
           lineText.RemoveLast();

    if ((11.5*(line+2)) <= maxhight)
        needHight += 11.5;
    
    outText.Remove(0,lineText.size());
    line++;
} while (line < 10 && !outText.empty());

int adjust = (unsigned int)needHight - maxhight;

if (adjust < -12)
{
    for (int i = eventNumber; i < dataBase->GetEventsCount(); i++)
        dataBase->AdjustTime2Y(i,adjust);
    DrawNote(cr, text, eventNumber);
    return;
}

outText = text;
line = 0;

yPixel -= 3;

setColor(cr, white);
cairo_set_line_width (cr, 0.8);
cairo_move_to(cr, xPixel-leftSide, yPixel);
cairo_rel_line_to(cr, 0, -hight);
cairo_rel_line_to(cr, leftSide + rightSide, 0);
cairo_rel_line_to(cr, edgeWidth, edgeHight);
cairo_rel_line_to(cr, 0, hight-edgeHight);
cairo_close_path(cr);
cairo_fill_preserve(cr);

cairo_set_source_rgb(cr, 0.4, 0.4, 0.4);
cairo_stroke (cr);

cairo_set_source_rgb(cr, 0.85, 0.85, 0.85);
cairo_move_to(cr, xPixel+rightSide, yPixel-hight);
cairo_rel_line_to(cr, 0, edgeHight);
cairo_rel_line_to(cr, edgeWidth, 0);
cairo_close_path(cr);
cairo_fill_preserve(cr);
cairo_set_source_rgb(cr, 0.4, 0.4, 0.4);
cairo_stroke (cr);

do
{
    lineText = (outText + " ").Left(34);
    cairo_text_extents_t theExtents;
    setColor(cr, black);
    
    double maxlen;
    if (line == 0)
        maxlen = leftSide + rightSide - (2*border);
    else
        maxlen = edgeWidth + leftSide + rightSide - (2*border);
    
    do
    {
        cairo_text_extents(cr, lineText.c_str(), &theExtents);
        if (theExtents.width > maxlen)
            lineText.RemoveLast();
    } while (theExtents.width > maxlen);

    while ((lineText.Find(' ') != wxNOT_FOUND || lineText.Find('-') != wxNOT_FOUND) &&
           lineText.Last() != ' ' && lineText.Last() != '-')
           lineText.RemoveLast();

    cairo_move_to(cr, xPixel-leftSide+border, (11.5*line) + yPixel-hight+12);
    cairo_show_text(cr, lineText.c_str());
    
    outText.Remove(0,lineText.size());
    line++;
} while (line < 10 && !outText.empty());
