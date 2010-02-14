if (dataBase->GetClassCount() == 0)
	return;

wxClientDC dc(this);
DoPrepareDC(dc);

wxPoint p = event.GetLogicalPosition(dc);
mouseOverClass = dataBase->GetObjectIDFromX(p.x);
mouseOverEvent = dataBase->GetTimeFromY(p.y);

wxString pos;

if (mouseOverEvent >= 0 && mouseOverEvent < dataBase->GetEventsCount())
{
	pos.Printf(wxS("Event: %d"), mouseOverEvent);

	theStatusBar->PushStatusText(pos, 0);
	theStatusBar->PushStatusText(dataBase->GetClassName(mouseOverClass), 1);
	theStatusBar->PushStatusText(dataBase->GetEventTimestamp(mouseOverEvent), 2);
}
else
{
	theStatusBar->PushStatusText(wxEmptyString, 0);
	theStatusBar->PushStatusText(wxEmptyString, 1);
	theStatusBar->PushStatusText(wxEmptyString, 2);
}

if (mouseOverClass < dataBase->GetClassCount())
{
    myToolTip->SetTip(dataBase->GetFunctionFromXY(p.x,p.y));
}
else
{
    myToolTip->SetTip(wxEmptyString);
}
