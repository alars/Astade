//~~ void Draw(wxDC& dc) [scPerson] ~~

if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
else
{
	if (male)
		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("BLUE")), 1, wxSOLID));
	else
		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 1, wxSOLID));
}

dc.SetBrush(*wxTRANSPARENT_BRUSH);

if (child)
{
	dc.DrawCircle(absGetDrawPosition().xCoord(),absGetDrawPosition().yCoord() - 25, 6);
	dc.DrawLine(absGetDrawPosition().xCoord(),absGetDrawPosition().yCoord() - 19, absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord());

	dc.DrawLine(absGetDrawPosition().xCoord(),absGetDrawPosition().yCoord() - 13, absGetDrawPosition().xCoord() + 13, absGetDrawPosition().yCoord() - 22);
	dc.DrawLine(absGetDrawPosition().xCoord(),absGetDrawPosition().yCoord() - 13, absGetDrawPosition().xCoord() - 13, absGetDrawPosition().yCoord() - 22);

	if (male)
	{
		dc.DrawLine(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord(), absGetDrawPosition().xCoord() + 13, absGetDrawPosition().yCoord() + 15);
		dc.DrawLine(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord(), absGetDrawPosition().xCoord() - 13, absGetDrawPosition().yCoord() + 15);
	}
	else
	{
		dc.SetBrush(*wxWHITE_BRUSH);
		dc.DrawLine(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord(), absGetDrawPosition().xCoord() + 7, absGetDrawPosition().yCoord() + 15);
		dc.DrawLine(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord(), absGetDrawPosition().xCoord() - 7, absGetDrawPosition().yCoord() + 15);

		wxPoint points[3];
		points[0] = wxPoint(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord() - 19);
		points[1] = wxPoint(absGetDrawPosition().xCoord() + 12, absGetDrawPosition().yCoord() + 12); 
		points[2] = wxPoint(absGetDrawPosition().xCoord() - 12, absGetDrawPosition().yCoord() + 12);

		dc.DrawPolygon(3, points);
	}
}
else
{
	dc.DrawCircle(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord() - 29, 9);
	dc.DrawLine(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord() - 20, absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord());

	dc.DrawLine(absGetDrawPosition().xCoord() - 15, absGetDrawPosition().yCoord() - 15, absGetDrawPosition().xCoord() + 15, absGetDrawPosition().yCoord() - 15);

	if (male)
	{
		dc.DrawLine(absGetDrawPosition().xCoord(),absGetDrawPosition().yCoord(), absGetDrawPosition().xCoord() + 15, absGetDrawPosition().yCoord() + 15);
		dc.DrawLine(absGetDrawPosition().xCoord(),absGetDrawPosition().yCoord(), absGetDrawPosition().xCoord() - 15, absGetDrawPosition().yCoord() + 15);
	}
	else
	{
		dc.SetBrush(*wxWHITE_BRUSH);
		dc.DrawLine(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord(), absGetDrawPosition().xCoord() + 7, absGetDrawPosition().yCoord() + 15);
		dc.DrawLine(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord(), absGetDrawPosition().xCoord() - 7, absGetDrawPosition().yCoord() + 15);

		wxPoint points[3];
		points[0] = wxPoint(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord() - 3);
		points[1] = wxPoint(absGetDrawPosition().xCoord() + 15, absGetDrawPosition().yCoord() + 12); 
		points[2] = wxPoint(absGetDrawPosition().xCoord() - 15, absGetDrawPosition().yCoord() + 12);

		dc.DrawPolygon(3, points);
	}
}


wxCoord y;
dc.GetTextExtent(myLabel, &labelwidth, &y);
dc.DrawText(myLabel, absGetDrawPosition().xCoord() - labelwidth / 2, absGetDrawPosition().yCoord() + 15);
