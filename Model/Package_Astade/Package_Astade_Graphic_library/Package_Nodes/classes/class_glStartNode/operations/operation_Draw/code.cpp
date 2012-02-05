//~~ void Draw(wxDC& dc) [glStartNode] ~~

if (isMouseOver())
{
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
	dc.SetBrush(wxTheColourDatabase->Find(wxS("RED")));
}
else
{
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("MAGENTA")), 1, wxSOLID));
	dc.SetBrush(wxTheColourDatabase->Find(wxS("MAGENTA")));
}

dc.DrawCircle(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord(), my_Radius);
