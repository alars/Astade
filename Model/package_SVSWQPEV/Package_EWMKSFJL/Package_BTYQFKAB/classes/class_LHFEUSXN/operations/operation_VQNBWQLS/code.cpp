if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
else
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"),1,wxSOLID));

dc.SetBrush(*wxWHITE);

dc.DrawRectangle(absGetDrawPosition().xCoord()-my_XRadius,absGetDrawPosition().yCoord()-my_YRadius,2*my_XRadius,2*my_YRadius);
dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"),1,wxSOLID));

glVector upperEdge(absGetDrawPosition());
upperEdge += glVector(my_XRadius, -my_YRadius);

glVector innerEdge(upperEdge);
innerEdge += glVector(-15,3);
dc.DrawRectangle(innerEdge.xCoord(),innerEdge.yCoord(),12,15);

innerEdge += glVector(-4,3);
dc.DrawRectangle(innerEdge.xCoord(),innerEdge.yCoord(),8,4);

innerEdge += glVector(0,5);
dc.DrawRectangle(innerEdge.xCoord(),innerEdge.yCoord(),8,4);

