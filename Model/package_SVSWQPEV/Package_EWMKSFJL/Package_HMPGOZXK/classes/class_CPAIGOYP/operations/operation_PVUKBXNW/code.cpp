if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
else
    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),1,wxSOLID));

dc.DrawLine(absDrawnStartPoint.xCoord(),absDrawnStartPoint.yCoord(),absDrawnEndPoint.xCoord(),absDrawnEndPoint.yCoord());

glVector interfacePos = GetEndNode().absGetDrawPosition();
glVector diff = (interfacePos - absDrawnEndPoint).Dir();
diff *= 10;
glVector diff1 = diff.Rotate90Degree();
glVector diff2 = diff1.Rotate90Degree();
glVector diff3 = diff2.Rotate90Degree();

glVector p1 = diff3 + interfacePos;
glVector p2 = diff1 + interfacePos;

dc.DrawArc(p1.xCoord(), p1.yCoord(), p2.xCoord(), p2.yCoord(), interfacePos.xCoord(), interfacePos.yCoord());

dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("WHITE"),2,wxSOLID));
dc.DrawLine(p1.xCoord(), p1.yCoord(), p2.xCoord(), p2.yCoord());
