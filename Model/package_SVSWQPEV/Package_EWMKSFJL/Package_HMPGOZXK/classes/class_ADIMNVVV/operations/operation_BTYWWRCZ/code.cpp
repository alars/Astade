glVector diff;
glVector endcenter;
glVector end = absGetEndPoint();

diff =  absGetStartPoint() - end;
diff =  diff.Dir();
diff *= 10;

glVector v = end + diff.RotateDegree(30);
dc.DrawLine(v.xCoord(),v.yCoord(),end.xCoord(),end.yCoord());
v = end + diff.RotateDegree(-30);
dc.DrawLine(v.xCoord(),v.yCoord(),end.xCoord(),end.yCoord());
