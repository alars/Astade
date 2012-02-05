//~~ void Draw(wxDC& dc) [glState] ~~

const int middleBorder = 6;
const int secondBorder = 6;

if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
else
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("MAGENTA")), 1, wxSOLID));

dc.SetBrush(*wxWHITE);
dc.SetTextForeground(wxTheColourDatabase->Find(wxS("BLACK")));

dc.DrawCircle(absGetDrawPosition().xCoord() - my_XRadius + my_edgeRadius, absGetDrawPosition().yCoord() - my_YRadius + my_edgeRadius, my_edgeRadius);
dc.DrawCircle(absGetDrawPosition().xCoord() + my_XRadius - my_edgeRadius, absGetDrawPosition().yCoord() - my_YRadius + my_edgeRadius, my_edgeRadius);
dc.DrawCircle(absGetDrawPosition().xCoord() - my_XRadius+my_edgeRadius, absGetDrawPosition().yCoord() + my_YRadius - my_edgeRadius, my_edgeRadius);
dc.DrawCircle(absGetDrawPosition().xCoord() + my_XRadius - my_edgeRadius, absGetDrawPosition().yCoord() + my_YRadius - my_edgeRadius, my_edgeRadius);

dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("WHITE")), 1, wxSOLID));

dc.DrawRectangle(absGetDrawPosition().xCoord() - my_XRadius + my_edgeRadius - 2, absGetDrawPosition().yCoord() - my_YRadius + my_edgeRadius - 2, 2 * (my_XRadius - my_edgeRadius) + 4, 2 * (my_YRadius - my_edgeRadius + 4));
dc.DrawRectangle(absGetDrawPosition().xCoord() - my_XRadius + my_edgeRadius, absGetDrawPosition().yCoord() - my_YRadius, 2 * (my_XRadius - my_edgeRadius), 2 * my_YRadius);
dc.DrawRectangle(absGetDrawPosition().xCoord() - my_XRadius, absGetDrawPosition().yCoord() - my_YRadius + my_edgeRadius, 2 * my_XRadius, 2 * (my_YRadius - my_edgeRadius));

if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
else
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("MAGENTA")), 1, wxSOLID));

dc.DrawLine(absGetDrawPosition().xCoord() - my_XRadius + my_edgeRadius,
			absGetDrawPosition().yCoord() - my_YRadius,
			absGetDrawPosition().xCoord() + my_XRadius - my_edgeRadius,
			absGetDrawPosition().yCoord() - my_YRadius);

dc.DrawLine(absGetDrawPosition().xCoord() - my_XRadius + my_edgeRadius,
			absGetDrawPosition().yCoord() + my_YRadius,
			absGetDrawPosition().xCoord() + my_XRadius - my_edgeRadius,
			absGetDrawPosition().yCoord() + my_YRadius);

dc.DrawLine(absGetDrawPosition().xCoord() - my_XRadius,
			absGetDrawPosition().yCoord() - my_YRadius + my_edgeRadius,
			absGetDrawPosition().xCoord() - my_XRadius,
			absGetDrawPosition().yCoord() + my_YRadius - my_edgeRadius);

dc.DrawLine(absGetDrawPosition().xCoord() + my_XRadius,
			absGetDrawPosition().yCoord() - my_YRadius + my_edgeRadius,
			absGetDrawPosition().xCoord() + my_XRadius,
			absGetDrawPosition().yCoord() + my_YRadius - my_edgeRadius);

wxCoord x, y;
dc.GetTextExtent(myLabel, &x, &y);

// Fits in one line?
if (x < (2 * my_XRadius) - middleBorder)
{
    dc.DrawText(myLabel, absGetDrawPosition().m_x - (x/2), absGetDrawPosition().m_y - (y/2));
    return;
}

// Fits in two lines?
wxString secondPart = myLabel;
wxString firstPart = cutSubstring(secondPart, dc, (2 * my_XRadius) - middleBorder);
dc.GetTextExtent(firstPart, &x, &y);

wxCoord x2, y2;
dc.GetTextExtent(secondPart, &x2, &y2);

if (x2 < (2 * my_XRadius) - middleBorder)
{
	dc.DrawText(firstPart, absGetDrawPosition().m_x - my_XRadius + (middleBorder/2), absGetDrawPosition().m_y - (y/2));
	dc.DrawText(secondPart, absGetDrawPosition().m_x - my_XRadius + (middleBorder/2), absGetDrawPosition().m_y + (y/2));
	return;
}

// Fits in three lines?
wxString thirdPart = myLabel;
firstPart = cutSubstring(thirdPart, dc, (2 * my_XRadius) - secondBorder);
secondPart = cutSubstring(thirdPart, dc, (2 * my_XRadius) - middleBorder);
shrinkString(thirdPart, dc, (2 * my_XRadius) - secondBorder);

wxCoord x3, y3;
dc.GetTextExtent(firstPart, &x, &y);
dc.GetTextExtent(secondPart, &x2, &y2);
dc.GetTextExtent(thirdPart, &x3, &y3);

dc.DrawText(firstPart, absGetDrawPosition().m_x - my_XRadius + (middleBorder/2), absGetDrawPosition().m_y - y -(y2/2));
dc.DrawText(secondPart, absGetDrawPosition().m_x - my_XRadius + (middleBorder/2), absGetDrawPosition().m_y - (y2/2));
dc.DrawText(thirdPart, absGetDrawPosition().m_x - my_XRadius + (middleBorder/2), absGetDrawPosition().m_y + (y2/2));
