//~~ void Draw(wxDC& dc) [glGuidance] ~~

if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
else
	dc.SetPen(*wxLIGHT_GREY_PEN);

dc.SetBrush(*wxTheBrushList->FindOrCreateBrush(wxTheColourDatabase->Find(wxS("Lemon Chiffon"))));

wxPoint pointlist[6];

pointlist[0] = wxPoint(absGetDrawPosition().xCoord() - 33, absGetDrawPosition().yCoord() - 33);
pointlist[1] = wxPoint(absGetDrawPosition().xCoord() - 33, absGetDrawPosition().yCoord() - 27);
pointlist[2] = wxPoint(absGetDrawPosition().xCoord() + 27, absGetDrawPosition().yCoord() + 33);
pointlist[3] = wxPoint(absGetDrawPosition().xCoord() + 33, absGetDrawPosition().yCoord() + 33);

dc.DrawPolygon(4, pointlist);

pointlist[0] = wxPoint(absGetDrawPosition().xCoord() - 34, absGetDrawPosition().yCoord() + 34);
pointlist[1] = wxPoint(absGetDrawPosition().xCoord() - 34, absGetDrawPosition().yCoord() - 34);
pointlist[2] = wxPoint(absGetDrawPosition().xCoord() - 12, absGetDrawPosition().yCoord() - 34);
pointlist[3] = wxPoint(absGetDrawPosition().xCoord() - 12, absGetDrawPosition().yCoord() + 12);
pointlist[4] = wxPoint(absGetDrawPosition().xCoord() + 34, absGetDrawPosition().yCoord() + 12);
pointlist[5] = wxPoint(absGetDrawPosition().xCoord() + 34, absGetDrawPosition().yCoord() + 34);

dc.DrawPolygon(6, pointlist);

dc.DrawLine(absGetDrawPosition().xCoord() - 24, absGetDrawPosition().yCoord() + 34, absGetDrawPosition().xCoord() - 24, absGetDrawPosition().yCoord() + 21);
dc.DrawLine(absGetDrawPosition().xCoord() - 10, absGetDrawPosition().yCoord() + 34, absGetDrawPosition().xCoord() - 10, absGetDrawPosition().yCoord() + 21);
dc.DrawLine(absGetDrawPosition().xCoord()  + 4, absGetDrawPosition().yCoord() + 34, absGetDrawPosition().xCoord()  + 4, absGetDrawPosition().yCoord() + 21);
dc.DrawLine(absGetDrawPosition().xCoord() + 18, absGetDrawPosition().yCoord() + 34, absGetDrawPosition().xCoord() + 18, absGetDrawPosition().yCoord() + 21);

dc.DrawLine(absGetDrawPosition().xCoord() - 17, absGetDrawPosition().yCoord() + 34, absGetDrawPosition().xCoord() - 17, absGetDrawPosition().yCoord() + 28);
dc.DrawLine(absGetDrawPosition().xCoord()  - 3, absGetDrawPosition().yCoord() + 34, absGetDrawPosition().xCoord()  - 3, absGetDrawPosition().yCoord() + 28);
dc.DrawLine(absGetDrawPosition().xCoord() + 11, absGetDrawPosition().yCoord() + 34, absGetDrawPosition().xCoord() + 11, absGetDrawPosition().yCoord() + 28);
dc.DrawLine(absGetDrawPosition().xCoord() + 25, absGetDrawPosition().yCoord() + 34, absGetDrawPosition().xCoord() + 25, absGetDrawPosition().yCoord() + 28);

wxCoord x, y;
dc.GetTextExtent(myLabel, &x, &y);

// Fits in one line?
if (x < (2.5 * my_Radius))
{
    dc.DrawText(myLabel, absGetDrawPosition().m_x - (x/2), absGetDrawPosition().m_y + 25 + y);
    return;
}

// Fits in two lines?
wxString secondPart = myLabel;
wxString firstPart = cutSubstring(secondPart, dc, (2.5 * my_Radius));
shrinkString(secondPart, dc, (2 * my_Radius));
dc.GetTextExtent(firstPart, &x, &y);

wxCoord x2, y2;
dc.GetTextExtent(secondPart, &x2, &y2);

dc.DrawText(firstPart, absGetDrawPosition().m_x - x/2, absGetDrawPosition().m_y + 23 + y);
dc.DrawText(secondPart, absGetDrawPosition().m_x - x2/2,absGetDrawPosition().m_y + 23 + (2*y));
