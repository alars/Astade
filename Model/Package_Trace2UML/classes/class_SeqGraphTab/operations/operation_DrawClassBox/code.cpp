//~~ void DrawClassBox(cairo_t* cr, int eventNumber, int objectNumber) [SeqGraphTab] ~~
/* vi: set tabstop=4: */
wxString name(dataBase->GetClassName(objectNumber));

double w, h;
wxCoord w2, h2;
wxString name2;

int pos = name.Find(wxS("\\n"));
if (pos >= 0)
{
	name2 = name.Mid(pos + 2);
	name = name.Left(pos);

    cairo_text_extents_t theExtents;
    cairo_text_extents(cr, name.c_str(), &theExtents);
    w = theExtents.width;
    h = theExtents.height;
    cairo_text_extents(cr, name2.c_str(), &theExtents);
    w2 = theExtents.width;
    h2 = theExtents.height;
}
else
{
    cairo_text_extents_t theExtents;
    cairo_text_extents(cr, name.c_str(), &theExtents);
    w = theExtents.width;
    h = theExtents.height;
}

int width = dataBase->GetClassBoxWidth(objectNumber);

int endY = eventNumber;
while ((endY < dataBase->GetEventsCount()) &&
       ((dataBase->GetDestinationIndex(endY) != objectNumber) ||
        ((dataBase->GetEventID(endY) != ID_GLOBALDELETE) &&
         (dataBase->GetEventID(endY) != ID_DELETE)
        )
       )
      )
    endY++;
    

setColor(cr, dashedgreen);
cairo_set_line_width (cr, 1.0);
cairo_move_to(cr, dataBase->GetClassMiddle(objectNumber), dataBase->GetTime2Y(eventNumber));
cairo_line_to (cr, dataBase->GetClassMiddle(objectNumber), dataBase->GetTime2Y(endY-1));
cairo_stroke (cr);

setColor(cr, white);
cairo_set_line_width (cr, 1);
cairo_rectangle(cr, dataBase->GetClassMiddle(objectNumber) - width / 2, 
                    dataBase->GetTime2Y(eventNumber) - dataBase->GetClassBoxHeight(),
                    width, dataBase->GetClassBoxHeight());
cairo_fill_preserve(cr);
setColor(cr, green);
cairo_stroke (cr);

setColor(cr, black);
if (name2.empty())
{
    cairo_move_to(cr, dataBase->GetClassMiddle(objectNumber) - w / 2,
                      dataBase->GetTime2Y(eventNumber) + h / 2 - dataBase->GetClassBoxHeight() / 2);
    cairo_show_text(cr, name.c_str());
}
else
{
    cairo_move_to(cr, dataBase->GetClassMiddle(objectNumber) - w / 2,
                      dataBase->GetTime2Y(eventNumber) - 1 - dataBase->GetClassBoxHeight() / 2);
    cairo_show_text(cr, name.c_str());
    cairo_move_to(cr, dataBase->GetClassMiddle(objectNumber) - w2 / 2,
                      dataBase->GetTime2Y(eventNumber) + h + 1 - dataBase->GetClassBoxHeight() / 2);
    cairo_show_text(cr, name2.c_str());
}
