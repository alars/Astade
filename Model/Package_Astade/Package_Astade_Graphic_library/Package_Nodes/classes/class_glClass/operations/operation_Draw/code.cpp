//~~ void Draw(wxDC& dc) [glClass] ~~

if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
else
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("BLUE")), 1, wxSOLID));

dc.SetBrush(*wxWHITE);

dc.DrawRectangle(absGetDrawPosition().xCoord() - my_XRadius,absGetDrawPosition().yCoord() - my_YRadius, 2 * my_XRadius, 2 * my_YRadius);
dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("BLUE")), 1, wxSOLID));

glVector lowerLeft(absGetDrawPosition());
lowerLeft += glVector(-my_XRadius, 0.6 * my_YRadius);
glVector lowerRight(lowerLeft);
lowerRight += glVector(2 * my_XRadius, 0);

// Active Lines
if (active)
{
  lowerLeft  += glVector(+0.1 * my_XRadius, 0);
  lowerRight += glVector(-0.1 * my_XRadius, 0);

  glVector upperLeft(absGetDrawPosition());
  upperLeft  += glVector(-0.9 * my_XRadius, -my_YRadius);
  glVector upperRight(absGetDrawPosition());
  upperRight += glVector(+0.9 * my_XRadius, -my_YRadius);
  
  dc.DrawLine(upperLeft.xCoord(), upperLeft.yCoord(), upperLeft.xCoord(), upperLeft.yCoord() + 2 * my_YRadius);
  dc.DrawLine(upperRight.xCoord(), upperRight.yCoord(), upperRight.xCoord(), upperRight.yCoord() + 2 * my_YRadius);
}

// Bottom Line
dc.DrawLine(lowerLeft.xCoord(), lowerLeft.yCoord(), lowerRight.xCoord(), lowerRight.yCoord());

/*
 * Draw Label
 */
if (!myLabel.IsEmpty())
{
    const int xCenter = absGetDrawPosition().m_x;
    int xWidth = 2 * my_XRadius - 20;
    const int yCenter = absGetDrawPosition().m_y - 0.2*my_YRadius;
    const int yHeight = 1.6 * my_YRadius - 20;
    if (active)
		xWidth -= 0.2 * my_XRadius;

    wxCoord x, y;
    dc.GetTextExtent(myLabel, &x, &y);

    const int maxLines = yHeight / y + 1;
    int lines = 0;

    wxString label = myLabel;
    wxString part;
    for (int i = 0; i < maxLines && !label.IsEmpty(); ++i)
    {
        part = cutSubstring(label, dc, xWidth);
        dc.GetTextExtent(part, &x, &y);
        ++lines;
    }

    label = myLabel;
    for (int i = 0; i < lines; ++i)
    {
        part = cutSubstring(label, dc, xWidth);
        dc.GetTextExtent(part, &x, &y);
        dc.DrawText(part, xCenter - (x/2), yCenter - y * (0.5 * lines - i - 0.25));
    }
}
