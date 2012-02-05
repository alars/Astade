//~~ void Draw(wxDC& dc) [glUseInterface] ~~

glVector interfacePos = GetEndNode().absGetDrawPosition();
glVector diff = (absDrawnEndPoint - absDrawnStartPoint).Dir();
diff *= 10;

glVector drawEnd = absDrawnEndPoint - diff;

if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
else
    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 1, wxSOLID));

int endPointX = drawEnd.xCoord();
int endPointY = drawEnd.yCoord();
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

dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 1, wxSOLID));

glVector diff1 = diff.Rotate90Degree();

for (int i = 0; i < 20; i++)
{
    glVector diff2 = diff1.RotateDegree(-9);
    dc.DrawLine((interfacePos - diff1).xCoord(), (interfacePos - diff1).yCoord(), (interfacePos - diff2).xCoord(), (interfacePos - diff2).yCoord());
    diff1 = diff2;
}
