//~~ void Draw(wxDC& dc) [glCreateArtefact] ~~

if (isMouseOver())
    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
else
    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("BLACK")), 1, wxSOLID));

dc.DrawLine(absDrawnStartPoint.xCoord(), absDrawnStartPoint.yCoord(), absDrawnEndPoint.xCoord(), absDrawnEndPoint.yCoord());

glVector dir = (absDrawnStartPoint - absDrawnEndPoint).Dir();
dir *= 14;

glVector p1 = dir.RotateDegree( 30) + absDrawnEndPoint;
glVector p2 = dir.RotateDegree(-30) + absDrawnEndPoint;

if (isMouseOver())
    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
else
    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("BLACK")), 1, wxSOLID));

dc.DrawLine(absDrawnEndPoint.xCoord(), absDrawnEndPoint.yCoord(), p1.xCoord(), p1.yCoord());
dc.DrawLine(absDrawnEndPoint.xCoord(), absDrawnEndPoint.yCoord(), p2.xCoord(), p2.yCoord());
