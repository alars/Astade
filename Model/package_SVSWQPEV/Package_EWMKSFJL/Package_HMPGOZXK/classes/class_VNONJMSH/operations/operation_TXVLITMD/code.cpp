if (width==0)
	return myStartNode.absGetNearestToNode(&myEndNode);
	
glVector centerPoint = absCalculateCenterPoint();

if (lastStartPoint == glVector())
	lastStartPoint = myStartNode.absGetPosition() - centerPoint;

lastStartPoint = lastStartPoint.Dir();
lastStartPoint *= (myStartNode.absGetPosition() - centerPoint).Mod();

while (myStartNode.isInElement(centerPoint + lastStartPoint))
	lastStartPoint = lastStartPoint.RotateRadians(M_PI * 0.5 / 180);

while (!myStartNode.isInElement(centerPoint + lastStartPoint))
	lastStartPoint = lastStartPoint.RotateRadians(-M_PI * 0.5 / 180);

return centerPoint +lastStartPoint;
