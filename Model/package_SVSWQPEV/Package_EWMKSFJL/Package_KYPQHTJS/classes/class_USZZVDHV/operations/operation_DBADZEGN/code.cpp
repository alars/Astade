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
  
double forceValue = 1/(distValue * distValue * distValue);

glVector ret = dist.Dir();

ret *= forceValue;

return ret;
