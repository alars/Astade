if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
else
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),1,wxSOLID));

dc.SetBrush(*wxTRANSPARENT_BRUSH);

dc.DrawCircle(absGetDrawPosition().xCoord(),absGetDrawPosition().yCoord()-29,9);
dc.DrawLine(absGetDrawPosition().xCoord(),absGetDrawPosition().yCoord()-20,absGetDrawPosition().xCoord(),absGetDrawPosition().yCoord());

dc.DrawLine(absGetDrawPosition().xCoord()-15,absGetDrawPosition().yCoord()-15,absGetDrawPosition().xCoord()+15,absGetDrawPosition().yCoord()-15);

dc.DrawLine(absGetDrawPosition().xCoord(),absGetDrawPosition().yCoord(),absGetDrawPosition().xCoord()+15,absGetDrawPosition().yCoord()+15);
dc.DrawLine(absGetDrawPosition().xCoord(),absGetDrawPosition().yCoord(),absGetDrawPosition().xCoord()-15,absGetDrawPosition().yCoord()+15);

wxCoord y;
dc.GetTextExtent(myLabel,&labelwidth,&y);
dc.DrawText(myLabel,absGetDrawPosition().xCoord()-(labelwidth/2),absGetDrawPosition().yCoord()+15);
