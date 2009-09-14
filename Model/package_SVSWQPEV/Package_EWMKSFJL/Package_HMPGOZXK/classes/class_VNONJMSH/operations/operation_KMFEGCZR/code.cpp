if (width==0)
	return myEndNode.absGetNearestToNode(&myStartNode);
	
glVector centerPoint = absCalculateCenterPoint();

if (lastEndPoint == glVector())
	lastEndPoint = myEndNode.absGetPosition() - centerPoint;

lastEndPoint = lastEndPoint.Dir();
lastEndPoint *= (myEndNode.absGetPosition() - centerPoint).Mod();

int count=30;
double rot;

if (width<0)
	rot = -0.5;
else
	rot = 0.5;

while ((--count > 0) && (myEndNode.isInElement(centerPoint + lastEndPoint)))
	lastEndPoint = lastEndPoint.RotateRadians(-M_PI * rot / 180);

count = 720;
while ((--count > 0) && (!myEndNode.isInElement(centerPoint + lastEndPoint)))
	lastEndPoint = lastEndPoint.RotateRadians(M_PI * rot / 180);

return centerPoint +lastEndPoint;
