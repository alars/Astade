//~~ void Draw(wxDC& dc) [glActor] ~~

if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
else
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 1, wxSOLID));

dc.SetBrush(*wxTRANSPARENT_BRUSH);

dc.DrawCircle(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord() - 29, 9);
dc.DrawLine(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord() - 20, absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord());

dc.DrawLine(absGetDrawPosition().xCoord() - 15, absGetDrawPosition().yCoord() - 15, absGetDrawPosition().xCoord() + 15, absGetDrawPosition().yCoord() - 15);

dc.DrawLine(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord(), absGetDrawPosition().xCoord() + 15, absGetDrawPosition().yCoord() + 15);
dc.DrawLine(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord(), absGetDrawPosition().xCoord() - 15, absGetDrawPosition().yCoord() + 15);

wxCoord x, y;
dc.GetTextExtent(myLabel, &x, &y);

// Fits in one line?
if (x < (2.5 * my_Radius))
{
    dc.DrawText(myLabel, absGetDrawPosition().m_x - (x/2), absGetDrawPosition().m_y + 15);
    return;
}

// Fits in two lines?
wxString secondPart = myLabel;
wxString firstPart = cutSubstring(secondPart, dc, (2.5 * my_Radius));
shrinkString(secondPart, dc, (2 * my_Radius));
dc.GetTextExtent(firstPart, &x, &y);

wxCoord x2, y2;
dc.GetTextExtent(secondPart, &x2, &y2);

dc.DrawText(firstPart, absGetDrawPosition().m_x - x/2, absGetDrawPosition().m_y + 13);
dc.DrawText(secondPart, absGetDrawPosition().m_x - x2/2,absGetDrawPosition().m_y + 13 + y);
