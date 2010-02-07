if (myStartNode.IsThisMyArea(&otherArea)) // no force onto my start node
  return glVector();

if (myEndNode.IsThisMyArea(&otherArea)) // no force onto my end node
  return glVector();
  
glVector nearestToMe = otherArea.absCalculateNearestToArea(this);
glVector nearestToIt = absCalculateNearestToArea(&otherArea);

glVector dist = nearestToMe-nearestToIt;
double distValue = dist.Mod();

if (distValue < 1)
  distValue = 1;
  
double forceValue = glFloatingConstants::instance().floatingMatrix[myType][otherArea.myType]/(distValue * distValue);

glVector ret = dist.Dir();
ret *= forceValue;

double endFactor = (nearestToIt - absGetEndPoint()).Mod();
double startFactor = (nearestToIt - absGetStartPoint()).Mod();
double totalDist = (absGetEndPoint() - absGetStartPoint()).Mod();

glVector endPointForce(ret);
endPointForce /= totalDist;
glVector startPointForce(endPointForce);

endPointForce *= endFactor;
endPointForces[&otherArea] = endPointForce;

startPointForce *= startFactor;
startPointForces[&otherArea] = startPointForce;

return ret;
