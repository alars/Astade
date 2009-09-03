if (radius==0)
	return myStartNode.absGetNearestToNode(&myEndNode);
	
glVector centerPoint = absCalculateCenterPoint();
if (lastStartPoint == glVector())
	lastStartPoint = myStartNode.absGetPosition() - centerPoint;

while (myStartNode.isInElement(centerPoint + lastStartPoint))
	lastStartPoint = lastStartPoint.RotateRadians(M_PI * 0.1 / 180);

while (!myStartNode.isInElement(centerPoint + lastStartPoint))
	lastStartPoint = lastStartPoint.RotateRadians(-M_PI * 0.1 / 180);

return centerPoint +lastStartPoint;
