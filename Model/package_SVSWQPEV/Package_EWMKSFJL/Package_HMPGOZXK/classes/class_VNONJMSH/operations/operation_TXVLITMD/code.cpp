if (width==0)
	return myStartNode.absGetNearestToNode(&myEndNode);
	
glVector centerPoint = absCalculateCenterPoint();

if (lastStartPoint == glVector())
	lastStartPoint = myStartNode.absGetPosition() - centerPoint;

lastStartPoint = lastStartPoint.Dir();
lastStartPoint *= (myStartNode.absGetPosition() - centerPoint).Mod();

double rot;

if (width<0)
	rot = -M_PI * 0.1 / 180;
else
	rot = M_PI * 0.1 / 180;

int count=300;
while ((--count > 0) && (myStartNode.isInElement(centerPoint + lastStartPoint)))
	lastStartPoint = lastStartPoint.RotateRadians(rot);

count = 3600;
while ((--count > 0) && (!myStartNode.isInElement(centerPoint + lastStartPoint)))
	lastStartPoint = lastStartPoint.RotateRadians(-rot);

return centerPoint +lastStartPoint;
