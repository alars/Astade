//~~ void Draw(wxDC& dc) [glArtefactComposition] ~~

if (isMouseOver())
    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
else
    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("BLACK")), 1, wxSOLID));

dc.DrawLine(absDrawnStartPoint.xCoord(), absDrawnStartPoint.yCoord(), absDrawnEndPoint.xCoord(), absDrawnEndPoint.yCoord());

glVector dir = (absDrawnStartPoint - absDrawnEndPoint).Dir();
dir *= 14;

glVector p1 = dir.RotateDegree( 30);
glVector p2 = dir.RotateDegree(-30);

dc.SetBrush(*wxLIGHT_GREY);

wxPoint points[4] = {
    wxPoint(absDrawnStartPoint.xCoord(),absDrawnStartPoint.yCoord()),
    wxPoint(absDrawnStartPoint.xCoord()-p1.xCoord(),absDrawnStartPoint.yCoord()-p1.yCoord()),
    wxPoint(absDrawnStartPoint.xCoord()-p1.xCoord()-p2.xCoord(),absDrawnStartPoint.yCoord()-p1.yCoord()-p2.yCoord()),
    wxPoint(absDrawnStartPoint.xCoord()-p2.xCoord(),absDrawnStartPoint.yCoord()-p2.yCoord())
};

dc.DrawPolygon(4, points);
