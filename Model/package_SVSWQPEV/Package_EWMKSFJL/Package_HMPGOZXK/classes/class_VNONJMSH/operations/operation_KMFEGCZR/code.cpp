if (width==0)
	return myEndNode.absGetNearestToNode(&myStartNode);
	
glVector centerPoint = absCalculateCenterPoint();

if (lastEndPoint == glVector())
	lastEndPoint = myEndNode.absGetPosition() - centerPoint;

lastEndPoint = lastEndPoint.Dir();
lastEndPoint *= (myEndNode.absGetPosition() - centerPoint).Mod();

double rot;

if (width<0)
	rot = -M_PI * 0.1 / 180;
else
	rot = M_PI * 0.1 / 180;

int count=300;
while ((--count > 0) && (myEndNode.isInElement(centerPoint + lastEndPoint)))
	lastEndPoint = lastEndPoint.RotateRadians(-rot);

count = 3600;
while ((--count > 0) && (!myEndNode.isInElement(centerPoint + lastEndPoint)))
	lastEndPoint = lastEndPoint.RotateRadians(rot);

return centerPoint +lastEndPoint;
