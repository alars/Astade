//~~ void Draw(wxDC& dc) [glSelfEdge] ~~

if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
else
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("BLUE")), 1, wxSOLID));

dc.SetBrush(*wxWHITE);

dc.DrawCircle(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord(), my_Radius);
