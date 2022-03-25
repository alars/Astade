//~~ void DrawEvent(std::ofstream& cr, int eventNumber) [SeqDrawIO] ~~
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

dataBase->SetThickness(eventNumber,thickness);

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
    }
    break;

    case ID_NOTE:
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

        ++thickness[stop];

        startPixel = 0;
        stopPixel = GetLeftSide(stop);

        DrawArrow(cr, eventNumber, startPixel, yPixel, stopPixel, yPixel, "block", dataBase->GetLabel(eventNumber), "#0000ff", false);
        DrawExecution(cr, GetRightSide(stop)-10, eventNumber, dataBase->findReturn(eventNumber));
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
        
        DrawArrow(cr, eventNumber, startPixel, yPixel, stopPixel, yPixel, "block", dataBase->GetLabel(eventNumber), "#0000ff", false);
        DrawExecution(cr, GetRightSide(stop)-10, eventNumber, dataBase->findReturn(eventNumber));
    }
    break;

    case ID_RECEIVE:
    {
        int start = dataBase->GetSourceIndex(eventNumber);
        int stop  = dataBase->GetDestinationIndex(eventNumber);

        if (thickness[stop] < 0)
            thickness[stop] = 0;

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

            DrawArrow(cr, eventNumber, startPixel, startYPixel, stopPixel, stopYPixel, "open", dataBase->GetLabel(eventNumber), "#0000ff", false);
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
    }
    break;

    case ID_GLOBALRECEIVE:
    break;

    case ID_SELFRECEIVE:
    break;

    case ID_SELFCALL:
    {
        int stop = dataBase->GetDestinationIndex(eventNumber);
        int yPixel = dataBase->GetTime2Y(eventNumber) - 12;

        if (thickness[stop] < 0)
            thickness[stop] = 0;

        int bogen = thickness[stop];
        if (bogen > MAXDEPTH)
            bogen = MAXDEPTH;

        bogen *= 4;
        bogen += 35;

        yPixel += 7;
        DrawSelfCall(cr, eventNumber);
        ++thickness[stop];
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

        DrawArrow(cr, eventNumber, startPixel, yPixel, stopPixel, yPixel, "open", dataBase->GetLabel(eventNumber), "#0000ff", true);
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

        DrawArrow(cr, eventNumber, startPixel, yPixel, stopPixel, yPixel, "open", dataBase->GetLabel(eventNumber), "#0000ff", true);
    }
    break;

    case ID_TASKSWITCH:
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

        DrawArrow(cr, eventNumber, startPixel,
                    yPixel,
                    dataBase->GetClassMiddle(dataBase->GetDestinationIndex(eventNumber))+offset,
                    yPixel, "block", wxS("create()"), "#008000", false);
    }
    break;

    case ID_GLOBALCREATE:
    {
        int yPixel = dataBase->GetTime2Y(eventNumber)-20;
        DrawArrow(cr, eventNumber, 0, yPixel,
                    dataBase->GetClassMiddle(dataBase->GetDestinationIndex(eventNumber))-(dataBase->GetClassBoxWidth(dataBase->GetDestinationIndex(eventNumber))/2),
                    yPixel, "block", wxS("create()"), "#008000", false);
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

        DrawCross(cr, eventNumber);

        //DrawArrow(cr, startPixel, yPixel,
        //            dataBase->GetClassMiddle(dataBase->GetDestinationIndex(eventNumber)),
        //            yPixel, ARROWHEADSOLID, wxS("delete()"), red);
        thickness[dataBase->GetDestinationIndex(eventNumber)] = -1;
    }
    break;

    case ID_GLOBALDELETE:
    {
        int yPixel = dataBase->GetTime2Y(eventNumber)-9;
        DrawCross(cr, eventNumber);

        //DrawArrow(cr, 0, yPixel,
        //            dataBase->GetClassMiddle(dataBase->GetDestinationIndex(eventNumber)),
        //            yPixel, ARROWHEADSOLID, wxS("delete()"), red);
        thickness[dataBase->GetDestinationIndex(eventNumber)] = -1;
    }
    break;
}

dataBase->SetThickness(eventNumber,thickness);
