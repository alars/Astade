if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
else
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"),1,wxSOLID));

dc.SetBrush(*wxWHITE);

dc.DrawCircle(absGetDrawPosition().xCoord(),absGetDrawPosition().yCoord(),my_Radius);
