if (dataBase->GetClassCount() == 0)
	return;

wxClientDC dc(this);
DoPrepareDC(dc);

wxPoint p = event.GetLogicalPosition(dc);
mouseOverClass = dataBase->GetObjectIDFromX(p.x);
mouseOverEvent = dataBase->GetTimeFromY(p.y);

if (mouseOverEvent >= 0 && mouseOverEvent < dataBase->GetEventsCount())
{
	wxString pos;
	pos.Printf(_T("Event: %d"), mouseOverEvent);

	theStatusBar->PushStatusText(pos, 0);
	theStatusBar->PushStatusText(dataBase->GetEventTimestamp(mouseOverEvent), 1);
}
else
{
	theStatusBar->PushStatusText(wxEmptyString, 0);
	theStatusBar->PushStatusText(wxEmptyString, 1);
}
