if (isMouseOver())
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
else
  dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("GREEN"),2,wxSOLID));

DrawArc(dc);

glVector endcenter = absCalculateCenterPoint() ;
glVector end = absGetEndPoint();

glVector diff = end - endcenter;
diff =  diff.Dir();
diff *= 10;
diff = diff.Rotate90Degree();

if (width > 0)
	diff *= -1;

glVector v = end + diff.RotateDegree(30);
dc.DrawLine(v.xCoord(),v.yCoord(),end.xCoord(),end.yCoord());
v = end + diff.RotateDegree(-30);
dc.DrawLine(v.xCoord(),v.yCoord(),end.xCoord(),end.yCoord());
