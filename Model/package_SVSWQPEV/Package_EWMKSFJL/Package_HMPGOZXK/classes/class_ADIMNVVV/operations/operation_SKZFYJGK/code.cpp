glVector diff;
glVector endcenter;
glVector end = absGetEndPoint();

diff =  absGetStartPoint() - end;
diff =  diff.Dir();
diff *= 10;

glVector u = end + diff.RotateDegree(30);
glVector v = end + diff.RotateDegree(-30);
wxPoint points[3] = { wxPoint(u.xCoord(),u.yCoord()), wxPoint(v.xCoord(),v.yCoord()), wxPoint(end.xCoord(),end.yCoord()) };

dc.DrawPolygon(3, points);
