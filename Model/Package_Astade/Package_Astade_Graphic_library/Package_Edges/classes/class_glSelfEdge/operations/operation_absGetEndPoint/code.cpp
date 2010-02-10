glVector dir = myNode.absGetPosition() -  absGetPosition();
dir = dir.Dir();
dir *= my_Radius;
int count = 360;

while((--count>0) && (myNode.isInElement(absGetPosition()+dir)))
    dir = dir.RotateDegree(1);

glVector end = absGetPosition()+dir;

return end;