//~~ void Draw(wxDC& dc) [glProvideInterface] ~~

if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
else
  dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 1, wxSOLID));

int endPointX = absDrawnEndPoint.xCoord();
int endPointY = absDrawnEndPoint.yCoord();
int startPointX = absDrawnStartPoint.xCoord();
int startPointY = absDrawnStartPoint.yCoord();

if (abs(endPointX - startPointX) <= 1)
{
	startPointX = endPointX;
}

if (abs(endPointY - startPointY) <= 1)
{
	startPointY = endPointY;
}

dc.DrawLine(startPointX, startPointY, endPointX, endPointY);
