glVector diff;
glVector endcenter;
glVector end = absGetStartPoint();

diff =  absGetEndPoint() - end;
diff =  diff.Dir();
diff *= 10;

glVector u = end - diff.RotateDegree(30);
glVector v = end - diff.RotateDegree(-30);
glVector w = v - diff.RotateDegree(30);

wxPoint points[4] = {
    wxPoint(u.xCoord(),u.yCoord()),
    wxPoint(w.xCoord(),w.yCoord()),
    wxPoint(v.xCoord(),v.yCoord()),
    wxPoint(end.xCoord(),end.yCoord())
};

dc.DrawPolygon(4, points);
