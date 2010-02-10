if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
else
    dc.SetPen(*wxThePenList->FindOrCreatePen(wxColor(0x40, 0x7a, 0x40),1,wxLONG_DASH));

dc.DrawLine(absDrawnStartPoint.xCoord(),absDrawnStartPoint.yCoord(),absDrawnEndPoint.xCoord(),absDrawnEndPoint.yCoord());
