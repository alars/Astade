//if (radius==0)
	return myEndNode.absGetNearestToNode(&myStartNode);
	
glVector centerPoint = absCalculateCenterPoint();

glVector diff = (lastEndPoint-centerPoint).Dir();
diff *= radius;
lastEndPoint = myStartNode.absGetBorderPoint(centerPoint + diff);
return lastEndPoint;
