if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
else
    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"),1,wxSOLID));

glVector m = absCalculateCenterPoint();

glVector mv = lastStartPoint + lastEndPoint;
mv = mv.Dir();
mv *= radius();
mv += m;

dc.DrawSpline(absDrawnStartPoint.xCoord(),absDrawnStartPoint.yCoord(), mv.xCoord(),mv.yCoord(), absDrawnEndPoint.xCoord(),absDrawnEndPoint.yCoord());

