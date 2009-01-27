glVector absStartPoint = absGetStartPoint();
glVector absEndPoint = absGetEndPoint();

dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"),1,wxSOLID));
dc.DrawLine(absStartPoint.xCoord(),absStartPoint.yCoord(),absEndPoint.xCoord(),absEndPoint.yCoord());