//~~ void DrawStartExecution(cairo_t* cr, int classIndex, int eventNumber) [SeqGraphTab] ~~
int theThickness = thickness[classIndex];

if (theThickness < 0)
	return;

if (theThickness >= MAXDEPTH)
	return;

int right = GetRightSide(classIndex);


int endY = eventNumber;

int depth = 0;
while (endY < dataBase->GetEventsCount())
{
    if (dataBase->GetDestinationIndex(endY) == classIndex)
    {
        if ((dataBase->GetEventID(endY) == ID_RETURN) ||
            (dataBase->GetEventID(endY) == ID_GLOBALRETURN) ||
            (dataBase->GetEventID(endY) == ID_TASKSWITCH) ||
            (dataBase->GetEventID(endY) == ID_SELFRETURN)
           )
        {   
            if (depth > 1)
                depth--;
            else
                break;
        }
        if ((dataBase->GetEventID(endY) == ID_CALL) ||
            (dataBase->GetEventID(endY) == ID_GLOBALCALL) ||
            (dataBase->GetEventID(endY) == ID_SELFCALL) ||
            (dataBase->GetEventID(endY) == ID_RECEIVEFUNC) ||
            (dataBase->GetEventID(endY) == ID_GLOBALRECEIVEFUNC) ||
            (dataBase->GetEventID(endY) == ID_SELFRECEIVEFUNC)
           )
        {   
            depth++;
        }
    }
    endY++;
}

if (endY == dataBase->GetEventsCount())
{
    setColor(cr, white);
    cairo_set_line_width (cr, 1);
    cairo_rectangle(cr, right - 4, dataBase->GetTime2Y(eventNumber)-5, 9, 6 + (dataBase->GetTime2Y(endY-1) - dataBase->GetTime2Y(eventNumber)));
    cairo_fill(cr);
    
    setColor(cr, green);
    cairo_move_to (cr, right - 4, dataBase->GetTime2Y(endY-1));
    cairo_rel_line_to (cr, 0, -(5 + dataBase->GetTime2Y(endY-1) - dataBase->GetTime2Y(eventNumber)));
    cairo_rel_line_to (cr, 9, 0);
    cairo_rel_line_to (cr, 0, 5 + dataBase->GetTime2Y(endY-1) - dataBase->GetTime2Y(eventNumber));
    cairo_stroke (cr);
}
else
{
    setColor(cr, white);
    cairo_set_line_width (cr, 1);
    cairo_rectangle(cr, right - 4, dataBase->GetTime2Y(eventNumber)-5, 9, dataBase->GetTime2Y(endY) - dataBase->GetTime2Y(eventNumber));
    cairo_fill_preserve(cr);
    setColor(cr, green);
    cairo_stroke (cr);
}