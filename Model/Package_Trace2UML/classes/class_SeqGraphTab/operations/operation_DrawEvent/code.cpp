//~~ void DrawEvent(cairo_t* cr, int eventNumber, bool clip = false) [SeqGraphTab] ~~
int aEventID = dataBase->GetEventID(eventNumber);

if (aEventID == ID_RETURN ||
	aEventID == ID_GLOBALRETURN ||
	aEventID == ID_SELFRETURN)
{
	int stop = dataBase->GetDestinationIndex(eventNumber);
	if (thickness[stop] > 0)
		--thickness[stop];
}

if (aEventID == ID_TASKSWITCH)
	if (thickness[dataBase->GetSourceIndex(eventNumber)] > 0)
		--thickness[dataBase->GetSourceIndex(eventNumber)];

if (aEventID == ID_EXIST)
{
	if (thickness[dataBase->GetDestinationIndex(eventNumber)] < 0)
		thickness[dataBase->GetDestinationIndex(eventNumber)] = 0;
}

bool shouldDraw = true;


if ((clip) && (aEventID != ID_EXIST) && (aEventID != ID_CLASSBOX))
{
    int yPixel = dataBase->GetTime2Y(eventNumber);

    if (yPixel+10 < m_scroll || yPixel-80 > m_scrollEnd)
        shouldDraw = false;
}

if (!shouldDraw && aEventID != ID_RECEIVE && aEventID != ID_SELFRECEIVE
                && aEventID != ID_SEND    && aEventID != ID_SELFSEND)
{
	int stop = dataBase->GetDestinationIndex(eventNumber);
    if (aEventID == ID_GLOBALCALL ||
        aEventID == ID_CALL ||
        aEventID == ID_TASKSWITCH ||
        aEventID == ID_SELFCALL)
    {
		DrawStartExecution(cr, stop, eventNumber);
    }
    
    if (aEventID == ID_GLOBALCALL ||
        aEventID == ID_CALL ||
        aEventID == ID_SELFCALL ||
        aEventID == ID_RECEIVEFUNC)
    {
		if (thickness[stop] < 0)
			thickness[stop] = 0;

		++thickness[stop];
    }
    else if (aEventID == ID_CREATE ||
        aEventID == ID_GLOBALCREATE)
    {
        thickness[stop] = 0;
    }
    else if (aEventID == ID_DELETE ||
        aEventID == ID_GLOBALDELETE)
    {
        thickness[stop] = -1;
    }
    dataBase->SetThickness(eventNumber,thickness);
    return;
}
else
    dataBase->SetThickness(eventNumber,thickness);

if (shouldDraw)
{
    if (aEventID == ID_PAUSE)
        for (int i = 0; i < dataBase->GetClassCount(); i++)
            if (thickness[i] >= 0)
                DrawPause(cr, i, eventNumber);
}

switch (dataBase->GetEventID(eventNumber))
{
    case ID_COMMENT:
        DrawComment(cr, dataBase->GetLabel(eventNumber), eventNumber);
    break;

    case ID_SEND:
    case ID_SELFSEND:
    {
        int start = dataBase->GetSourceIndex(eventNumber);
        int stop  = dataBase->GetDestinationIndex(eventNumber);
        if (thickness[stop] < 0)
            thickness[stop] = 0;
        eventQueue[stop].push_back(eventNumber);

        if (start > stop)
            dataBase->SetSourceX(start,GetLeftSide(start));
        else
            dataBase->SetSourceX(start,GetRightSide(start));
            
        DrawTimeLine(cr, start, eventNumber);
    }
    break;

    case ID_NOTE:
        DrawNote(cr, dataBase->GetLabel(eventNumber), eventNumber);
    break;

    case ID_REFERENCE:
        DrawRef(cr, dataBase->GetLabel(eventNumber), eventNumber);
    break;

    case ID_STATECHANGE:
        DrawStatechange(cr, dataBase->GetLabel(eventNumber), eventNumber);
    break;

    case ID_GLOBALCALL:
    {
        int stop = dataBase->GetDestinationIndex(eventNumber);
        int startPixel;
        int stopPixel;
        int yPixel = dataBase->GetTime2Y(eventNumber)-5;

        if (thickness[stop] < 0)
            thickness[stop] = 0;

        DrawStartExecution(cr, stop, eventNumber);
        ++thickness[stop];

        startPixel = 0;
        stopPixel = GetLeftSide(stop);

        DrawArrow(cr, startPixel, yPixel, stopPixel, yPixel, ARROWHEADSOLID, dataBase->GetLabel(eventNumber), blue);
            
        DrawTimeLine(cr, stop, eventNumber);
    }
    break;

    case ID_CALL:
    {
        int start = dataBase->GetSourceIndex(eventNumber);
        int stop = dataBase->GetDestinationIndex(eventNumber);
        int startPixel;
        int stopPixel;
        int yPixel = dataBase->GetTime2Y(eventNumber) - 5;

        if (thickness[stop] < 0)
            thickness[stop] = 0;

        DrawStartExecution(cr, stop, eventNumber);
        ++thickness[stop];

        if (start > stop)
        {
            startPixel = GetLeftSide(start);
            stopPixel = GetRightSide(stop);
        }
        else
        {
            startPixel = GetRightSide(start);
            stopPixel = GetLeftSide(stop);
        }
        
        DrawArrow(cr, startPixel, yPixel, stopPixel, yPixel, ARROWHEADSOLID, dataBase->GetLabel(eventNumber), blue);
            
        DrawTimeLine(cr, start, eventNumber);
    }
    break;

    case ID_RECEIVE:
    case ID_RECEIVEFUNC:
    {
        int start = dataBase->GetSourceIndex(eventNumber);
        int stop  = dataBase->GetDestinationIndex(eventNumber);

        if (thickness[stop] < 0)
            thickness[stop] = 0;

        if (dataBase->GetEventID(eventNumber) == ID_RECEIVEFUNC)
        {
            DrawStartExecution(cr, stop, eventNumber);
            ++thickness[stop];
        }

        std::list<int>::iterator it;
        for (it = eventQueue[stop].begin(); it != eventQueue[stop].end(); ++it)
            if (dataBase->GetSourceIndex(*it) == start &&
                dataBase->GetLabel(*it) == dataBase->GetLabel(eventNumber))
                break;
        if (it != eventQueue[stop].end())
        {
            int startYPixel = dataBase->GetTime2Y(*it) - 4;
            eventQueue[stop].erase(it);

            int startPixel;
            int stopPixel;

            startPixel = dataBase->GetSourceX(start);

            if (start > stop)
                stopPixel = GetRightSide(stop);
            else
                stopPixel = GetLeftSide(stop);

            int stopYPixel = dataBase->GetTime2Y(eventNumber)-4;

            DrawArrow(cr, startPixel, startYPixel, stopPixel, stopYPixel, ARROWHEADVEE, dataBase->GetLabel(eventNumber), blue);
        }
        else
        {
            if (!eventQueue[stop].empty())
            {
                DrawLostEvent(cr, eventQueue[stop].front());
                eventQueue[stop].pop_front();
                DrawEvent(cr, eventNumber);
            }
            else
                DrawFoundEvent(cr, eventNumber);
        }
            
        DrawTimeLine(cr, stop, eventNumber);
    }
    break;

    case ID_GLOBALRECEIVE:
    case ID_GLOBALRECEIVEFUNC:
    {
        int stop = dataBase->GetDestinationIndex(eventNumber);

        if (thickness[stop] < 0)
            thickness[stop] = 0;

        if (dataBase->GetEventID(eventNumber) == ID_GLOBALRECEIVEFUNC)
        {
            DrawStartExecution(cr, stop, eventNumber);
            ++thickness[stop];
        }

        int startPixel = 0;
        int stopPixel;

        stopPixel = GetLeftSide(stop);

        int stopYPixel = dataBase->GetTime2Y(eventNumber)-4;
        int startYPixel = stopYPixel;

        DrawArrow(cr, startPixel, startYPixel, stopPixel, stopYPixel, ARROWHEADVEE, dataBase->GetLabel(eventNumber), blue);
            
        DrawTimeLine(cr, stop, eventNumber);
    }
    break;

    case ID_SELFRECEIVE:
    case ID_SELFRECEIVEFUNC:
    {
        int start = dataBase->GetSourceIndex(eventNumber);
        int stop  = dataBase->GetDestinationIndex(eventNumber);

        if (thickness[stop] < 0)
            thickness[stop] = 0;

        if (dataBase->GetEventID(eventNumber) == ID_SELFRECEIVEFUNC)
        {
            DrawStartExecution(cr, stop, eventNumber);
            ++thickness[stop];
        }

        std::list<int>::iterator it;
        for (it = eventQueue[stop].begin(); it != eventQueue[stop].end(); ++it)
            if (dataBase->GetSourceIndex(*it) == start &&
                dataBase->GetLabel(*it) == dataBase->GetLabel(eventNumber))
                break;
        if (it != eventQueue[stop].end())
        {
            int startYPixel = dataBase->GetTime2Y(*it) - 4;
            eventQueue[stop].erase(it);

            int startPixel = dataBase->GetSourceX(start);
            int stopPixel = GetRightSide(stop);
            int stopYPixel = dataBase->GetTime2Y(eventNumber) - 4;
            int midYPixel = startYPixel + (stopYPixel - startYPixel) / 2;

            DrawArrow(cr, startPixel, startYPixel, startPixel+50, midYPixel, ARROWHEADNONE, dataBase->GetLabel(eventNumber), blue);
            DrawArrow(cr, startPixel+50, midYPixel, stopPixel, stopYPixel, ARROWHEADVEE, wxEmptyString, blue);
        }
        else
            DrawFoundEvent(cr, eventNumber);
            
        DrawTimeLine(cr, stop, eventNumber);
    }
    break;

    case ID_SELFCALL:
    {
        int stop = dataBase->GetDestinationIndex(eventNumber);
        int startPixel;
        int stopPixel;
        int yPixel = dataBase->GetTime2Y(eventNumber) - 12;

        if (thickness[stop] < 0)
            thickness[stop] = 0;

        int bogen = thickness[stop];
        if (bogen > MAXDEPTH)
            bogen = MAXDEPTH;

        bogen *= 4;
        bogen += 35;

        startPixel = dataBase->GetClassMiddle(dataBase->GetSourceIndex(eventNumber)) + bogen;
        stopPixel = GetRightSide(stop);
        DrawArrow(cr, startPixel, yPixel, stopPixel, yPixel, ARROWHEADNONE, dataBase->GetLabel(eventNumber), blue);

        yPixel += 7;
        DrawStartExecution(cr, stop, eventNumber);
        ++thickness[stop];

        stopPixel = GetRightSide(stop);

        DrawArrow(cr, startPixel, yPixel-7, startPixel, yPixel, ARROWHEADNONE, wxEmptyString, blue);
        DrawArrow(cr, startPixel, yPixel, stopPixel, yPixel, ARROWHEADSOLID, wxEmptyString, blue);
            
        DrawTimeLine(cr, stop, eventNumber);
    }
    break;

    case ID_GLOBALRETURN:
    {
        int start = dataBase->GetDestinationIndex(eventNumber);
        int startPixel;
        int stopPixel;
        int yPixel = dataBase->GetTime2Y(eventNumber)-5;

        ++thickness[start];
        startPixel = GetLeftSide(start);
        stopPixel = 0;
        --thickness[start];

        DrawArrow(cr, startPixel, yPixel, stopPixel, yPixel, ARROWHEADVEE, dataBase->GetLabel(eventNumber), dashedblue);
            
        DrawTimeLine(cr, start, eventNumber);
    }
    break;

    case ID_RETURN:
    {
        int start = dataBase->GetDestinationIndex(eventNumber);
        int stop = dataBase->GetSourceIndex(eventNumber);
        int startPixel;
        int stopPixel;
        int yPixel = dataBase->GetTime2Y(eventNumber) - 5;
        int relEvent = dataBase->GetRelEvent(eventNumber);
        if (relEvent == 0)
            relEvent = eventNumber-1;

        ++thickness[start];
        if (start > stop)
        {
            startPixel = GetLeftSide(start, relEvent);
            stopPixel = GetRightSide(stop);
        }
        else
        {
            startPixel = GetRightSide(start);
            stopPixel = GetLeftSide(stop, relEvent);
        }
        --thickness[start];

        DrawArrow(cr, startPixel, yPixel, stopPixel, yPixel, ARROWHEADVEE, dataBase->GetLabel(eventNumber), dashedblue);
            
        DrawTimeLine(cr, start, eventNumber);
    }
    break;

    case ID_TASKSWITCH:
    {
        int start = dataBase->GetSourceIndex(eventNumber);
        int stop = dataBase->GetDestinationIndex(eventNumber);
        int startPixel;
        int stopPixel;
        int yPixel = dataBase->GetTime2Y(eventNumber) - 5;

        if (thickness[stop] < 0)
            thickness[stop] = 0;

        DrawStartExecution(cr, stop, eventNumber);
        ++thickness[stop];

        ++thickness[start];
        if (start > stop)
        {
            startPixel = GetLeftSide(start);
            stopPixel = GetRightSide(stop);
        }
        else
        {
            startPixel = GetRightSide(start);
            stopPixel = GetLeftSide(stop);
        }
        --thickness[start];

        DrawArrow(cr, startPixel, yPixel, stopPixel, yPixel, ARROWHEADVEE, dataBase->GetLabel(eventNumber), dashedblue);
    }
    break;

    case ID_EXIST:
    case ID_CLASSBOX:
        DrawClassBox(cr, eventNumber, dataBase->GetDestinationIndex(eventNumber));
    break;

    case ID_CREATE:
    {
        int start = dataBase->GetSourceIndex(eventNumber);
        int stop = dataBase->GetDestinationIndex(eventNumber);
        int startPixel;
        int yPixel = dataBase->GetTime2Y(eventNumber) - dataBase->GetClassBoxHeight() / 2;

        if (start > stop)
            startPixel = GetLeftSide(start);
        else
            startPixel = GetRightSide(start);

        int offset = dataBase->GetClassBoxWidth(dataBase->GetDestinationIndex(eventNumber)) / 2;
        if (dataBase->GetSourceIndex(eventNumber) < dataBase->GetDestinationIndex(eventNumber))
            offset *= -1;

        DrawArrow(cr, startPixel,
                    yPixel,
                    dataBase->GetClassMiddle(dataBase->GetDestinationIndex(eventNumber))+offset,
                    yPixel, ARROWHEADSOLID, wxS("create()"), green);
        thickness[dataBase->GetDestinationIndex(eventNumber)] = 0;
    }
    break;

    case ID_GLOBALCREATE:
    {
        int yPixel = dataBase->GetTime2Y(eventNumber)-(dataBase->GetClassBoxHeight()/2);
        DrawArrow(cr, 0, yPixel,
                    dataBase->GetClassMiddle(dataBase->GetDestinationIndex(eventNumber))-(dataBase->GetClassBoxWidth(dataBase->GetDestinationIndex(eventNumber))/2),
                    yPixel, ARROWHEADSOLID, wxS("create()"), green);
        thickness[dataBase->GetDestinationIndex(eventNumber)] = 0;
    }
    break;

    case ID_DELETE:
    {
        int start = dataBase->GetSourceIndex(eventNumber);
        int stop = dataBase->GetDestinationIndex(eventNumber);
        int startPixel;
        int yPixel = dataBase->GetTime2Y(eventNumber) - 9;

        if (start > stop)
            startPixel = GetLeftSide(start);
        else
            startPixel = GetRightSide(start);

        DrawCross(cr, dataBase->GetClassMiddle(dataBase->GetDestinationIndex(eventNumber)), yPixel);

        DrawArrow(cr, startPixel, yPixel,
                    dataBase->GetClassMiddle(dataBase->GetDestinationIndex(eventNumber)),
                    yPixel, ARROWHEADSOLID, wxS("delete()"), red);
        thickness[dataBase->GetDestinationIndex(eventNumber)] = -1;
    }
    break;

    case ID_GLOBALDELETE:
    {
        int yPixel = dataBase->GetTime2Y(eventNumber)-9;
        DrawCross(cr, dataBase->GetClassMiddle(dataBase->GetDestinationIndex(eventNumber)), yPixel);

        DrawArrow(cr, 0, yPixel,
                    dataBase->GetClassMiddle(dataBase->GetDestinationIndex(eventNumber)),
                    yPixel, ARROWHEADSOLID, wxS("delete()"), red);
        thickness[dataBase->GetDestinationIndex(eventNumber)] = -1;
    }
    break;
}

dataBase->SetThickness(eventNumber,thickness);
