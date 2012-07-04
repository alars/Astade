//~~ void Draw(wxDC& dc) [scRelation] ~~

if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
else
    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("BLACK")), 1, wxSOLID));

dc.DrawLine(absDrawnStartPoint.xCoord(), absDrawnStartPoint.yCoord(), absDrawnEndPoint.xCoord(), absDrawnEndPoint.yCoord());
