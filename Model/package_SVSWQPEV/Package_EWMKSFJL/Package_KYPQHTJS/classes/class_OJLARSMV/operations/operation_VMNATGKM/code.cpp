glVector absPosition = absGetCenterPoint();
glVector absLeftPosition = absGetBorderPoint(absPosition + glVector(-1,0));
glVector absRightPosition = absGetBorderPoint(absPosition + glVector(1,0));
glVector absUpPosition = absGetBorderPoint(absPosition + glVector(0,-1));
glVector absDownPosition = absGetBorderPoint(absPosition + glVector(0,1));

double rightForce = -1;
double leftForce = 1;
double topForce = 1;
double bottonForce = -1;


if ((width - absRightPosition.xCoord()) > 1)
	rightForce = -1.0 / (width - absRightPosition.xCoord());

if ((absLeftPosition.xCoord()) > 1)
	leftForce = 1.0 / (absLeftPosition.xCoord());

if ((absUpPosition.yCoord()) > 1)
	topForce = 1.0 / (absUpPosition.yCoord());

if ((height - absDownPosition.yCoord()) > 1)
	bottonForce = -1.0 / (height - absDownPosition.yCoord());


glVector retval(rightForce+leftForce, topForce+bottonForce);

return retval;