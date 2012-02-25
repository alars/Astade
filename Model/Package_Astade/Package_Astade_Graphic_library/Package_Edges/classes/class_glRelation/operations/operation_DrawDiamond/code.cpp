//~~ void DrawDiamond(wxDC& dc) [glRelation] ~~
glVector end = absGetStartPoint();
glVector endcenter = absCalculateCenterPoint() ;

glVector diff = end - endcenter;
glVector diff2 = diff.RotateDegree(40*30/diff.Mod());

glVector orto = diff.Dir();
orto *= 6;

diff =  diff.Rotate90Degree().Dir();
diff *= 10;

glVector u = end + diff - orto;
glVector v = end + diff + orto;
glVector w = endcenter + diff2;

wxPoint points[4] = {
    wxPoint(v.xCoord(),v.yCoord()),
    wxPoint(w.xCoord(),w.yCoord()),
    wxPoint(u.xCoord(),u.yCoord()),
    wxPoint(end.xCoord(),end.yCoord())
};

dc.DrawPolygon(4, points);
