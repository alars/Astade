dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("SEA GREEN"), 1, wxSOLID));
dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("WHITE"), wxSOLID));

//Uncomment for debugging
//dc.DrawLine(0,dataBase->GetTime2Y(eventNumber),dataBase->GetGraphWidth(),dataBase->GetTime2Y(eventNumber));

if ((dataBase->GetEventID(eventNumber) == ID_RETURN) ||
	(dataBase->GetEventID(eventNumber) == ID_GLOBALRETURN) ||
	(dataBase->GetEventID(eventNumber) == ID_SELFRETURN)
	)
	if (thickness[dataBase->GetDestinationIndex(eventNumber)] > 0)
		--thickness[dataBase->GetDestinationIndex(eventNumber)];

if ((dataBase->GetEventID(eventNumber) == ID_TASKSWITCH)
	)
	if (thickness[dataBase->GetSourceIndex(eventNumber)] > 0)
		--thickness[dataBase->GetSourceIndex(eventNumber)];

if (dataBase->GetEventID(eventNumber) == ID_EXIST)
{
	if (thickness[dataBase->GetDestinationIndex(eventNumber)] < 0)
		thickness[dataBase->GetDestinationIndex(eventNumber)] = 0;
}

for (int i = 0; i < dataBase->GetClassCount(); i++)
	DrawLifeLine(dc, i, eventNumber, thickness[i]);

switch (dataBase->GetEventID(eventNumber))
{
	case ID_COMMENT:
		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("PURPLE"), 1, wxLONG_DASH));
		dc.DrawLine(0, dataBase->GetTime2Y(eventNumber)-14, dataBase->GetGraphWidth(), dataBase->GetTime2Y(eventNumber)-14);
		dc.DrawText(dataBase->GetLabel(eventNumber), 14, dataBase->GetTime2Y(eventNumber)-14);
	break;

	case ID_SEND:
	case ID_SELFSEND:
	{
		int start = dataBase->GetSourceIndex(eventNumber);
		int stop = dataBase->GetDestinationIndex(eventNumber);
		if (thickness[stop] < 0)
			thickness[stop] = 0;
		eventQueue[dataBase->GetDestinationIndex(eventNumber)].push_back(eventNumber);

		if (start>stop)
			dataBase->SetSourceX(start,GetLeftSide(start));
		else
			dataBase->SetSourceX(start,GetRightSide(start));
	}
	break;

	case ID_STATECHANGE:
	{
		int start = dataBase->GetSourceIndex(eventNumber);
		int yPixel = dataBase->GetTime2Y(eventNumber)-6;
		int xPixel = dataBase->GetClassMiddle(start);

		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"),1,wxSOLID ));
		dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("YELLOW"),wxSOLID));
		dc.DrawRoundedRectangle(xPixel-42, yPixel-12, 84, 18, 3);

		wxString name = dataBase->GetLabel(eventNumber);
		wxCoord w,h;
		dc.GetTextExtent(name, &w, &h);
		dc.DrawText(name, xPixel-(w/2), yPixel-(h/2)-3);
	}
	break;

	case ID_GLOBALCALL:
	{
		int stop = dataBase->GetDestinationIndex(eventNumber);
		int startPixel;
		int stopPixel;
		int yPixel = dataBase->GetTime2Y(eventNumber)-5;

		if (thickness[stop] < 0)
			thickness[stop] = 0;

		DrawStartExecution(dc, stop, yPixel);
		++thickness[stop];

		startPixel = 0;
		stopPixel = GetLeftSide(stop);

		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"), 1, wxSOLID));
		dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("BLUE"), wxSOLID));
		DrawArrow(dc, startPixel, yPixel, stopPixel, yPixel, ARROWHEADSOLID, dataBase->GetLabel(eventNumber));
	}
	break;

	case ID_CALL:
	{
		int start = dataBase->GetSourceIndex(eventNumber);
		int stop = dataBase->GetDestinationIndex(eventNumber);
		int startPixel;
		int stopPixel;
		int yPixel = dataBase->GetTime2Y(eventNumber)-5;

		if (thickness[stop] < 0)
			thickness[stop] = 0;

		DrawStartExecution(dc, stop, yPixel);
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

		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"), 1, wxSOLID));
		dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("BLUE"), wxSOLID));
		DrawArrow(dc, startPixel, yPixel, stopPixel, yPixel, ARROWHEADSOLID, dataBase->GetLabel(eventNumber));
	}
	break;

	case ID_RECEIVE:
	{
		int start = dataBase->GetSourceIndex(eventNumber);
		int stop = dataBase->GetDestinationIndex(eventNumber);

		if (thickness[stop] < 0)
			thickness[stop] = 0;

		if ((!eventQueue[stop].empty()) &&
			(dataBase->GetSourceIndex(eventQueue[stop].front()) == start) &&
			(dataBase->GetLabel(eventQueue[stop].front()) == dataBase->GetLabel(eventNumber))
			)
		{
			int startYPixel = dataBase->GetTime2Y(eventQueue[stop].front())-3;
			eventQueue[stop].pop_front();

			int startPixel;
			int stopPixel;

			startPixel = dataBase->GetSourceX(start);

			if (start>stop)
				stopPixel = GetRightSide(stop);
			else
				stopPixel = GetLeftSide(stop);

			int stopYPixel = dataBase->GetTime2Y(eventNumber)-3;

			dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"), 1, wxSOLID));
			dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("BLUE"), wxSOLID));
			DrawArrow(dc, startPixel, startYPixel, stopPixel, stopYPixel, ARROWHEADVEE, dataBase->GetLabel(eventNumber));
		}
		else
		{
			if (!eventQueue[stop].empty())
			{
				DrawLostEvent(dc,eventQueue[stop].front());
				eventQueue[stop].pop_front();
				DrawEvent(dc,eventNumber);
			}
			else
				DrawFoundEvent(dc,eventNumber);
		}
	}
	break;

	case ID_GLOBALRECEIVE:
	{
		int stop = dataBase->GetDestinationIndex(eventNumber);

		if (thickness[stop] < 0)
			thickness[stop] = 0;

		int startPixel = 0;
		int stopPixel;

		stopPixel = GetLeftSide(stop);

		int stopYPixel = dataBase->GetTime2Y(eventNumber)-3;
		int startYPixel = stopYPixel;

		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"), 1, wxSOLID));
		dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("BLUE"), wxSOLID));
		DrawArrow(dc, startPixel, startYPixel, stopPixel, stopYPixel, ARROWHEADVEE, dataBase->GetLabel(eventNumber));
	}
	break;

	case ID_SELFRECEIVE:
	{
		int start = dataBase->GetSourceIndex(eventNumber);
		int stop = dataBase->GetDestinationIndex(eventNumber);

		if (thickness[stop] < 0)
			thickness[stop] = 0;

		if ((!eventQueue[stop].empty()) &&
			(dataBase->GetSourceIndex(eventQueue[stop].front()) == start) &&
			(dataBase->GetLabel(eventQueue[stop].front()) == dataBase->GetLabel(eventNumber))
			)
		{
			int startYPixel = dataBase->GetTime2Y(eventQueue[stop].front())-3;
			eventQueue[stop].pop_front();

			int startPixel = dataBase->GetSourceX(start);
			int stopPixel = GetRightSide(stop);
			int stopYPixel = dataBase->GetTime2Y(eventNumber)-3;
			int midYPixel = startYPixel + ((stopYPixel - startYPixel)/2);

			dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"), 1, wxSOLID));
			dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("BLUE"), wxSOLID));
			DrawArrow(dc, startPixel, startYPixel, startPixel+50, midYPixel, ARROWHEADNONE, dataBase->GetLabel(eventNumber));
			DrawArrow(dc, startPixel+50, midYPixel, stopPixel, stopYPixel, ARROWHEADVEE, wxEmptyString);
		}
		else
			DrawFoundEvent(dc,eventNumber);
	}
	break;

	case ID_SELFCALL:
	{
		int stop = dataBase->GetDestinationIndex(eventNumber);
		int startPixel;
		int stopPixel;
		int yPixel = dataBase->GetTime2Y(eventNumber)-12;

		if (thickness[stop] < 0)
			thickness[stop] = 0;

		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"), 1, wxSOLID));
		dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("BLUE"), wxSOLID));

		startPixel = dataBase->GetClassMiddle(dataBase->GetSourceIndex(eventNumber)) + 50;
		stopPixel = GetRightSide(stop);
		DrawArrow(dc, startPixel, yPixel, stopPixel, yPixel, ARROWHEADNONE, dataBase->GetLabel(eventNumber));

		yPixel += 7;
		DrawStartExecution(dc,stop,yPixel);
		++thickness[stop];

		startPixel = dataBase->GetClassMiddle(dataBase->GetSourceIndex(eventNumber)) + 50;
		stopPixel = GetRightSide(stop);

		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"), 1, wxSOLID));
		dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("BLUE"), wxSOLID));
		dc.DrawLine(startPixel, yPixel-7, startPixel, yPixel);
		DrawArrow(dc, startPixel, yPixel, stopPixel, yPixel, ARROWHEADSOLID, wxEmptyString);
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

		DrawEndExecution(dc, start, eventNumber);
		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"), 1, wxSHORT_DASH));
		dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("BLUE"), wxSOLID));
		DrawArrow(dc, startPixel,
					yPixel, stopPixel, yPixel, ARROWHEADVEE, dataBase->GetLabel(eventNumber));
	}
	break;

	case ID_RETURN:
	{
		int start = dataBase->GetDestinationIndex(eventNumber);
		int stop = dataBase->GetSourceIndex(eventNumber);
		int startPixel;
		int stopPixel;
		int yPixel = dataBase->GetTime2Y(eventNumber)-5;

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

		DrawEndExecution(dc, start, eventNumber);
		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"), 1, wxSHORT_DASH));
		dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("BLUE"), wxSOLID));
		DrawArrow(dc, startPixel,
					yPixel, stopPixel, yPixel, ARROWHEADVEE, dataBase->GetLabel(eventNumber));
	}
	break;

	case ID_TASKSWITCH:
	{
		int start = dataBase->GetSourceIndex(eventNumber);
		int stop = dataBase->GetDestinationIndex(eventNumber);
		int startPixel;
		int stopPixel;
		int yPixel = dataBase->GetTime2Y(eventNumber)-5;

		if (thickness[stop] < 0)
			thickness[stop] = 0;

		DrawStartExecution(dc, stop, yPixel);
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

		DrawEndExecution(dc, start, eventNumber);
		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"), 1, wxSHORT_DASH));
		dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("BLUE"), wxSOLID));
		DrawArrow(dc, startPixel,
					yPixel, stopPixel, yPixel, ARROWHEADVEE, dataBase->GetLabel(eventNumber));
	}
	break;

	case ID_SELFRETURN:
	{
		int start = dataBase->GetDestinationIndex(eventNumber);
		DrawEndExecution(dc, start, eventNumber);
	}
	break;

	case ID_EXIST:
	case ID_CLASSBOX:
		DrawClassBox(dc, eventNumber, dataBase->GetDestinationIndex(eventNumber));
	break;

	case ID_CREATE:
	{
		int start = dataBase->GetSourceIndex(eventNumber);
		int stop = dataBase->GetDestinationIndex(eventNumber);
		int startPixel;
		int yPixel = dataBase->GetTime2Y(eventNumber)-(dataBase->GetClassBoxHeight()/2);

		if (start > stop)
			startPixel = GetLeftSide(start);
		else
			startPixel = GetRightSide(start);

		int offset = dataBase->GetClassBoxWidth(dataBase->GetDestinationIndex(eventNumber))/2;
		if (dataBase->GetSourceIndex(eventNumber) < dataBase->GetDestinationIndex(eventNumber))
			offset *= -1;

		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("FOREST GREEN"), 1, wxSOLID));
		dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("FOREST GREEN"), wxSOLID));
		DrawArrow(dc, startPixel,
					yPixel,
					dataBase->GetClassMiddle(dataBase->GetDestinationIndex(eventNumber))+offset,
					yPixel, ARROWHEADSOLID, "create()");
		thickness[dataBase->GetDestinationIndex(eventNumber)] = 0;
	}
	break;

	case ID_GLOBALCREATE:
	{
		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("FOREST GREEN"), 1, wxSOLID));
		dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("FOREST GREEN"), wxSOLID));
		int yPixel = dataBase->GetTime2Y(eventNumber)-(dataBase->GetClassBoxHeight()/2);
		DrawArrow(dc, 0,
					yPixel,
					dataBase->GetClassMiddle(dataBase->GetDestinationIndex(eventNumber))-(dataBase->GetClassBoxWidth(dataBase->GetDestinationIndex(eventNumber))/2),
					yPixel, ARROWHEADSOLID, "create()");
		thickness[dataBase->GetDestinationIndex(eventNumber)] = 0;
	}
	break;

	case ID_DELETE:
	{
		int start = dataBase->GetSourceIndex(eventNumber);
		int stop = dataBase->GetDestinationIndex(eventNumber);
		int startPixel;
		int yPixel = dataBase->GetTime2Y(eventNumber)-9;

		if (start > stop)
			startPixel = GetLeftSide(start);
		else
			startPixel = GetRightSide(start);

		DrawCross(dc, dataBase->GetClassMiddle(dataBase->GetDestinationIndex(eventNumber)), yPixel, "SEA GREEN");

		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"), 1, wxSOLID));
		dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("RED"), wxSOLID));
		DrawArrow(dc, startPixel,
					yPixel,
					dataBase->GetClassMiddle(dataBase->GetDestinationIndex(eventNumber)),
					yPixel, ARROWHEADSOLID, "delete()");
		thickness[dataBase->GetDestinationIndex(eventNumber)] = -1;
	}
	break;

	case ID_GLOBALDELETE:
	{
		int yPixel = dataBase->GetTime2Y(eventNumber)-9;
		DrawCross(dc, dataBase->GetClassMiddle(dataBase->GetDestinationIndex(eventNumber)), yPixel, "SEA GREEN");

		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"), 1, wxSOLID));
		dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("RED"), wxSOLID));
		DrawArrow(dc, 0,
					yPixel,
					dataBase->GetClassMiddle(dataBase->GetDestinationIndex(eventNumber)),
					yPixel, ARROWHEADSOLID, "delete()");
		thickness[dataBase->GetDestinationIndex(eventNumber)] = -1;
	}
	break;
}
