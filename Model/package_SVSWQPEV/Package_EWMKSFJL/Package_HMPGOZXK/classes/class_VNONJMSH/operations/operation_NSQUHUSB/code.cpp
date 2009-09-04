if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
else
    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"),1,wxSOLID));

dc.DrawLine(absDrawnStartPoint.xCoord(),absDrawnStartPoint.yCoord(),absDrawnEndPoint.xCoord(),absDrawnEndPoint.yCoord());


glVector m = absCalculateCenterPoint();
glVector mv = lastStartPoint + lastEndPoint;
mv = mv.Dir();
mv *= radius;
mv += m;

dc.DrawSpline(absDrawnStartPoint.xCoord(),absDrawnStartPoint.yCoord(), mv.xCoord(),mv.yCoord(), absDrawnEndPoint.xCoord(),absDrawnEndPoint.yCoord());

dc.DrawCircle(m.xCoord(),m.yCoord(),3);
