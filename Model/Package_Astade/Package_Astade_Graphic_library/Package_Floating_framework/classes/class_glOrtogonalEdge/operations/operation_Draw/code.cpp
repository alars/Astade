//~~ void Draw(wxDC& dc) [glSimpleEdge] ~~

if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
else
    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("BLUE")), 1, wxSOLID));

dc.DrawLine(absDrawnStartPoint.xCoord(), absDrawnStartPoint.yCoord(), absDrawnEndPoint.xCoord(), absDrawnEndPoint.yCoord());
