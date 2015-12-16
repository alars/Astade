//~~ glVector getEndPointForce() [glStraightEdge] ~~
glVector sum;

for (std::map<glArea*, glVector>::const_iterator it = endPointForces.begin(); it != endPointForces.end(); it++)
{
    sum += (*it).second;
}

return sum;
