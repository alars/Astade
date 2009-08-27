if (radius==0)
	return myStartNode.absGetNearestToNode(&myEndNode);
	
glVector centerPoint = absCalculateCenterPoint();

glVector diff = (lastStartPoint-centerPoint).Dir();
diff *= radius;
lastStartPoint = myStartNode.absGetBorderPoint(centerPoint + diff);
return lastStartPoint;
