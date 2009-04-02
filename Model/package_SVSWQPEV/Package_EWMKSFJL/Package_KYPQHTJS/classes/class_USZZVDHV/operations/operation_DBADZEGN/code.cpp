if (myStartNode.IsThisMyArea(&otherArea)) // no force onto my start node
  return glVector();

if (myEndNode.IsThisMyArea(&otherArea)) // no force onto my end node
  return glVector();
  
glVector nearestToMe = otherArea.absCalculateNearestToArea(this);
glSegment aSegment(absGetStartPoint(), absGetEndPoint());
glSegment::position aPosition = aSegment.Locate(nearestToMe);

glVector nearestToIt = aSegment.absGetNearestPoint(nearestToMe,aPosition);

glVector dist = nearestToMe-nearestToIt;
double distValue = dist.Mod();

if (distValue < 1)
  distValue = 1;
  
double forceValue = 20 * 1/(distValue * distValue * distValue);

glVector ret = dist.Dir();

ret *= forceValue;

return ret;
