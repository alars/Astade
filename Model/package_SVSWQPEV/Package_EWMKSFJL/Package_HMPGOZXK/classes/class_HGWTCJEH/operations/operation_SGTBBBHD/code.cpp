if (isMouseOver())
{
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
	dc.SetTextForeground(wxTheColourDatabase->Find("RED"));
}
else
{
	dc.SetTextForeground(wxTheColourDatabase->Find("MEDIUM SEA GREEN"));
    dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("MEDIUM SEA GREEN"),1,wxSOLID));
}

DrawArc(dc);

glVector diff;
glVector endcenter;
glVector end = absGetEndPoint();

if (width==0)
{
	diff = 	absGetStartPoint() - end;
	diff =  diff.Dir();
	diff *= 10;
}
else
{
	endcenter = absCalculateCenterPoint() ;

	diff = end - endcenter;
	diff =  diff.Dir();
	diff *= 10;
	diff = diff.Rotate90Degree();
}

if (width > 0)
	diff *= -1;

glVector v = end + diff.RotateDegree(30);
dc.DrawLine(v.xCoord(),v.yCoord(),end.xCoord(),end.yCoord());
v = end + diff.RotateDegree(-30);
dc.DrawLine(v.xCoord(),v.yCoord(),end.xCoord(),end.yCoord());

dc.SetTextForeground(wxTheColourDatabase->Find("BLACK"));
const_cast<glTransition*>(this)->myLabel.Draw(dc);

