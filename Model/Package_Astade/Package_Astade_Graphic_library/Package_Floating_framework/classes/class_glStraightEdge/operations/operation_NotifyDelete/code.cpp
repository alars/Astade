//~~ void NotifyDelete(glArea* anArea) [glStraightEdge] ~~
startPointForces.erase(anArea);
endPointForces.erase(anArea);
glGravityArea::NotifyDelete(anArea);
