//~~ glVector GetForceFromArea(glGravityArea& otherArea) [glCircularGravityArea] ~~
glVector otherBorder = otherArea.absCalculateNearestToArea(this);
glVector myBorder = absCalculateNearestToArea(&otherArea);

glVector direction = (otherBorder - myBorder);
double distance = direction.Mod();
if (distance < 1)
  distance = 1;

glVector ret = direction.Dir();
ret *= glFloatingConstants::instance().floatingMatrix[myType][otherArea.myType] / (distance*distance);

return ret;
