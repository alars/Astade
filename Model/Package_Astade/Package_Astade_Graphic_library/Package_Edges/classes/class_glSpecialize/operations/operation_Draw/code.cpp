//~~ void Draw(wxDC& dc) [glSpecialize] ~~

if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
else
    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("BLUE")), 1, wxSOLID));

dc.SetBrush(*wxWHITE);

dc.DrawLine(absDrawnStartPoint.xCoord(), absDrawnStartPoint.yCoord(), absDrawnEndPoint.xCoord(), absDrawnEndPoint.yCoord());

glVector dir = (absDrawnStartPoint - absDrawnEndPoint).Dir();
dir *= 14;

glVector p1 = dir.RotateDegree( 30) + absDrawnEndPoint;
glVector p2 = dir.RotateDegree(-30) + absDrawnEndPoint;

wxPoint pointlist[3] = {wxPoint(p1.xCoord(), p1.yCoord()),
                        wxPoint(absDrawnEndPoint.xCoord(), absDrawnEndPoint.yCoord()), 
                        wxPoint(p2.xCoord(), p2.yCoord())
                       };  

dc.DrawPolygon(3, pointlist);
