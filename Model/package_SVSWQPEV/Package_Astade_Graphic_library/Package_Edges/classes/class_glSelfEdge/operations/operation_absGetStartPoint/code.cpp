glVector dir = myNode.absGetPosition() -  absGetPosition();
dir = dir.Dir();
dir *= my_Radius;
int count = 0;

while((++count<360) && (myNode.isInElement(absGetPosition()+dir)))
    dir = dir.RotateDegree(1);

glVector end = absGetPosition()+dir;

return end;