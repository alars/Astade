if (width==0)
	return myStartNode.absGetNearestToNode(&myEndNode);
	
glVector centerPoint = absCalculateCenterPoint();

if (lastStartPoint == glVector())
	lastStartPoint = myStartNode.absGetPosition() - centerPoint;

lastStartPoint = lastStartPoint.Dir();
lastStartPoint *= (myStartNode.absGetPosition() - centerPoint).Mod();

int count=30;
while ((--count > 0) && (myStartNode.isInElement(centerPoint + lastStartPoint)))
	lastStartPoint = lastStartPoint.RotateRadians(M_PI * 0.5 / 180);

count = 720;
while ((--count > 0) && (!myStartNode.isInElement(centerPoint + lastStartPoint)))
	lastStartPoint = lastStartPoint.RotateRadians(-M_PI * 0.5 / 180);

return centerPoint +lastStartPoint;
