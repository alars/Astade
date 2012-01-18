//~~ void Draw(wxDC& dc) [glGuidance] ~~
if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
else
	dc.SetPen(*wxLIGHT_GREY_PEN);

dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find("YELLOW")));

wxPoint pointlist[6];

pointlist[0] = wxPoint(absGetDrawPosition().xCoord()-33,absGetDrawPosition().yCoord()-33);
pointlist[1] = wxPoint(absGetDrawPosition().xCoord()-33,absGetDrawPosition().yCoord()-27);
pointlist[2] = wxPoint(absGetDrawPosition().xCoord()+27,absGetDrawPosition().yCoord()+33);
pointlist[3] = wxPoint(absGetDrawPosition().xCoord()+33,absGetDrawPosition().yCoord()+33);

dc.DrawPolygon(4,pointlist);

pointlist[0] = wxPoint(absGetDrawPosition().xCoord()-34,absGetDrawPosition().yCoord()+34);
pointlist[1] = wxPoint(absGetDrawPosition().xCoord()-34,absGetDrawPosition().yCoord()-34);
pointlist[2] = wxPoint(absGetDrawPosition().xCoord()-12,absGetDrawPosition().yCoord()-34);
pointlist[3] = wxPoint(absGetDrawPosition().xCoord()-12,absGetDrawPosition().yCoord()+12);
pointlist[4] = wxPoint(absGetDrawPosition().xCoord()+34,absGetDrawPosition().yCoord()+12);
pointlist[5] = wxPoint(absGetDrawPosition().xCoord()+34,absGetDrawPosition().yCoord()+34);

dc.DrawPolygon(6,pointlist);

dc.DrawLine(absGetDrawPosition().xCoord()-24,absGetDrawPosition().yCoord()+34,absGetDrawPosition().xCoord()-24,absGetDrawPosition().yCoord()+21);
dc.DrawLine(absGetDrawPosition().xCoord()-10,absGetDrawPosition().yCoord()+34,absGetDrawPosition().xCoord()-10,absGetDrawPosition().yCoord()+21);
dc.DrawLine(absGetDrawPosition().xCoord() +4,absGetDrawPosition().yCoord()+34,absGetDrawPosition().xCoord() +4,absGetDrawPosition().yCoord()+21);
dc.DrawLine(absGetDrawPosition().xCoord()+18,absGetDrawPosition().yCoord()+34,absGetDrawPosition().xCoord()+18,absGetDrawPosition().yCoord()+21);

dc.DrawLine(absGetDrawPosition().xCoord()-17,absGetDrawPosition().yCoord()+34,absGetDrawPosition().xCoord()-17,absGetDrawPosition().yCoord()+28);
dc.DrawLine(absGetDrawPosition().xCoord() -3,absGetDrawPosition().yCoord()+34,absGetDrawPosition().xCoord() -3,absGetDrawPosition().yCoord()+28);
dc.DrawLine(absGetDrawPosition().xCoord()+11,absGetDrawPosition().yCoord()+34,absGetDrawPosition().xCoord()+11,absGetDrawPosition().yCoord()+28);
dc.DrawLine(absGetDrawPosition().xCoord()+25,absGetDrawPosition().yCoord()+34,absGetDrawPosition().xCoord()+25,absGetDrawPosition().yCoord()+28);

wxCoord y;
dc.GetTextExtent(myLabel,&labelwidth,&y);
dc.DrawText(myLabel,absGetDrawPosition().xCoord()-(labelwidth/2),absGetDrawPosition().yCoord()+36);
