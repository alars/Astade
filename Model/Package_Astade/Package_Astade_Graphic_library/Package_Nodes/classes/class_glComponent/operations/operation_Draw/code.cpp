//~~ void Draw(wxDC& dc) [glComponent] ~~

const int middleBorder = 4;
const int secondBorder = 20;

if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
else
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("BLUE")), 1, wxSOLID));

dc.SetBrush(*wxWHITE);

dc.DrawRectangle(absGetDrawPosition().xCoord() - my_XRadius,absGetDrawPosition().yCoord() - my_YRadius, 2 * my_XRadius, 2 * my_YRadius);
dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("BLUE")), 1, wxSOLID));

glVector upperEdge(absGetDrawPosition());
upperEdge += glVector(my_XRadius, -my_YRadius);

glVector innerEdge(upperEdge);
innerEdge += glVector(-15,3);
dc.DrawRectangle(innerEdge.xCoord(), innerEdge.yCoord(), 12, 15);

innerEdge += glVector(-4, 3);
dc.DrawRectangle(innerEdge.xCoord(),innerEdge.yCoord(),8,4);

innerEdge += glVector(0, 5);
dc.DrawRectangle(innerEdge.xCoord(),innerEdge.yCoord(), 8, 4);

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
	dc.DrawText(secondPart, absGetDrawPosition().m_x - my_XRadius + (middleBorder/2),absGetDrawPosition().m_y + (y/2));
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
