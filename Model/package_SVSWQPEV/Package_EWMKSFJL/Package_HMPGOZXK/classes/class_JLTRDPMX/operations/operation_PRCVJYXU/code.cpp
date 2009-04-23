if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
else
    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),1,wxSOLID));

dc.DrawLine(absDrawnStartPoint.xCoord(),absDrawnStartPoint.yCoord(),absDrawnEndPoint.xCoord(),absDrawnEndPoint.yCoord());
