if (dataBase->GetClassCount()==0)
	return;

wxClientDC dc(this);
DoPrepareDC(dc);

wxPoint p = event.GetLogicalPosition(dc);
mouseOverClass = dataBase->GetObjectIDFromX(p.x);
mouseOverEvent = dataBase->GetTimeFromY(p.y);

wxString pos;
pos.Printf("Event: %d",mouseOverEvent);

theStatusBar->PushStatusText(pos,0);

theStatusBar->PushStatusText(dataBase->GetEventTimestamp(mouseOverEvent),1);