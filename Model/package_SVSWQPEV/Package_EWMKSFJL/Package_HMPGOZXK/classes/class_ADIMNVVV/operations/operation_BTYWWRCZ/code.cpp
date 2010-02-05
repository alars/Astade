glVector dir = myNode.absGetPosition() -  absGetPosition();
dir = dir.Dir();
dir *= my_Radius;
int count = 0;

while((++count<360) && (myNode.isInElement(absGetPosition()+dir)))
    dir = dir.RotateDegree(-1);

glVector end = absGetPosition() + dir;

glVector diff =  dir.Rotate90Degree().Dir();
diff *= -10;

glVector v = end + diff.RotateDegree(25);
dc.DrawLine(v.xCoord(),v.yCoord(),end.xCoord(),end.yCoord());
v = end + diff.RotateDegree(-35);
dc.DrawLine(v.xCoord(),v.yCoord(),end.xCoord(),end.yCoord());
