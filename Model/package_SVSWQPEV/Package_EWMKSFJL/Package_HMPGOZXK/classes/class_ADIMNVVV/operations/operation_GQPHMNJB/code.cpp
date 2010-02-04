glVector dir = myNode.absGetPosition() -  absGetPosition();
dir = dir.Dir();
dir *= my_Radius;
int count = 0;

while((++count<360) && (myNode.isInElement(absGetPosition()+dir)))
    dir = dir.RotateDegree(1);

glVector end = absGetPosition() + dir;
glVector endcenter = absGetPosition() + dir.RotateDegree(40);

glVector diff = end - endcenter;
diff =  diff.Dir();
diff *= -10;

glVector orto = diff.Rotate90Degree().Dir();
orto *= 6;

glVector u = end + diff - orto;
glVector v = end + diff + orto;

wxPoint points[4] = {
    wxPoint(v.xCoord(),v.yCoord()),
    wxPoint(endcenter.xCoord(),endcenter.yCoord()),
    wxPoint(u.xCoord(),u.yCoord()),
    wxPoint(end.xCoord(),end.yCoord())
};

dc.DrawPolygon(4, points);
