//~~ void Draw(wxDC& dc) [glSelfTransition] ~~

if (isMouseOver())
{
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("RED")), 2, wxSOLID));
	dc.SetTextForeground(wxTheColourDatabase->Find(wxS("RED")));
}
else
{
	dc.SetTextForeground(wxTheColourDatabase->Find(wxS("BLACK")));
    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find(wxS("MEDIUM SEA GREEN")), 1, wxSOLID));
}

dc.SetBrush(*wxTRANSPARENT_BRUSH);

dc.DrawCircle(absGetDrawPosition().xCoord(), absGetDrawPosition().yCoord(), my_Radius);

glVector dir = myNode.absGetPosition() - absGetPosition();
dir = dir.Dir();
dir *= my_Radius;
int count = 0;

while (++count < 360 && myNode.isInElement(absGetPosition() + dir))
    dir = dir.RotateDegree(1);

glVector end = absGetPosition() + dir;

glVector diff = dir.Rotate90Degree();
diff =  diff.Dir();
diff *= 10;

glVector v = end + diff.RotateDegree(35);
dc.DrawLine(v.xCoord(), v.yCoord(), end.xCoord(), end.yCoord());
v = end + diff.RotateDegree(-25);
dc.DrawLine(v.xCoord(), v.yCoord(), end.xCoord(), end.yCoord());

const_cast<glSelfTransition*>(this)->myLabel.Draw(dc);

