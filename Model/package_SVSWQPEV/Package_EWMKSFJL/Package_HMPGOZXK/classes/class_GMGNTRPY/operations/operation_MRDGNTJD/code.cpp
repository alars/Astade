dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"),1,wxSOLID));

dc.DrawLine(absDrawnStartPoint.xCoord(),absDrawnStartPoint.yCoord(),absDrawnEndPoint.xCoord(),absDrawnEndPoint.yCoord());
