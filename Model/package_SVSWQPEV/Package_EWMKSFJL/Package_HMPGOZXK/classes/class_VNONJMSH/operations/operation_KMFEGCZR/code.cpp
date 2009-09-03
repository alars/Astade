if (radius==0)
	return myEndNode.absGetNearestToNode(&myStartNode);
	
glVector centerPoint = absCalculateCenterPoint();
if (lastEndPoint == glVector())
	lastEndPoint = myEndNode.absGetPosition() - centerPoint;

while (myEndNode.isInElement(centerPoint + lastEndPoint))
	lastEndPoint = lastEndPoint.RotateRadians(-M_PI * 0.1 / 180);

while (!myEndNode.isInElement(centerPoint + lastEndPoint))
	lastEndPoint = lastEndPoint.RotateRadians(M_PI * 0.1 / 180);

return centerPoint +lastEndPoint;
