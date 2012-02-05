//~~ void Draw(wxDC& dc) [glActivity] ~~

const int arrowlen = 14;
const int Border = (2*arrowlen) + 2;

if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
else
	dc.SetPen(*wxLIGHT_GREY_PEN);

dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find(wxS("Lemon Chiffon"))));

wxPoint pointlist[6];

pointlist[0] = wxPoint(absGetDrawPosition().xCoord()-(my_XRadius         ), absGetDrawPosition().yCoord() - my_YRadius);
pointlist[1] = wxPoint(absGetDrawPosition().xCoord()-(my_XRadius-arrowlen), absGetDrawPosition().yCoord()             );
pointlist[2] = wxPoint(absGetDrawPosition().xCoord()-(my_XRadius         ), absGetDrawPosition().yCoord() + my_YRadius);
pointlist[3] = wxPoint(absGetDrawPosition().xCoord()+(my_XRadius-arrowlen), absGetDrawPosition().yCoord() + my_YRadius);
pointlist[4] = wxPoint(absGetDrawPosition().xCoord()+(my_XRadius         ), absGetDrawPosition().yCoord()             );
pointlist[5] = wxPoint(absGetDrawPosition().xCoord()+(my_XRadius-arrowlen), absGetDrawPosition().yCoord() - my_YRadius);

dc.DrawPolygon(6, pointlist);

wxCoord x, y;
dc.GetTextExtent(myLabel, &x, &y);

// Fits in one line?
if (x < (2 * my_XRadius) - Border)
{
    dc.DrawText(myLabel, absGetDrawPosition().m_x - (x/2), absGetDrawPosition().m_y - (y/2));
    return;
}

// Fits in two lines?
wxString secondPart = myLabel;
wxString firstPart = cutSubstring(secondPart, dc, (2 * my_XRadius) - Border);
dc.GetTextExtent(firstPart, &x, &y);

wxCoord x2, y2;
dc.GetTextExtent(secondPart, &x2, &y2);

if (x2 < (2 * my_XRadius) - Border)
{
	dc.DrawText(firstPart, absGetDrawPosition().m_x - my_XRadius+(Border/2), absGetDrawPosition().m_y - (y/2));
	dc.DrawText(secondPart, absGetDrawPosition().m_x - my_XRadius+(Border/2), absGetDrawPosition().m_y + (y/2));
	return;
}

// Fits in three lines?

wxString thirdPart = myLabel;
firstPart = cutSubstring(thirdPart, dc, (2 * my_XRadius) - Border);
secondPart = cutSubstring(thirdPart, dc, (2 * my_XRadius) - Border);
shrinkString(thirdPart, dc, (2 * my_XRadius) - Border);

wxCoord x3, y3;
dc.GetTextExtent(firstPart, &x, &y);
dc.GetTextExtent(secondPart, &x2, &y2);
dc.GetTextExtent(thirdPart, &x3, &y3);

dc.DrawText(firstPart, absGetDrawPosition().m_x-my_XRadius + (Border/2), absGetDrawPosition().m_y - y - (y2/2));
dc.DrawText(secondPart, absGetDrawPosition().m_x-my_XRadius + (Border/2), absGetDrawPosition().m_y - (y2/2));
dc.DrawText(thirdPart, absGetDrawPosition().m_x-my_XRadius + (Border/2), absGetDrawPosition().m_y + (y2/2));
