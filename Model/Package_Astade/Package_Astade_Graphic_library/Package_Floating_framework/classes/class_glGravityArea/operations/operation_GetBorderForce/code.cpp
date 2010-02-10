glVector absPosition = absGetCenterPoint();
glVector absLeftPosition = absGetBorderPoint(absPosition + glVector(-100000,0));
glVector absRightPosition = absGetBorderPoint(absPosition + glVector(100000,0));
glVector absUpPosition = absGetBorderPoint(absPosition + glVector(0,-100000));
glVector absDownPosition = absGetBorderPoint(absPosition + glVector(0,100000));

double rightForce = -1;
double leftForce = 1;
double topForce = 1;
double bottonForce = -1;


if ((xPanelSize - absRightPosition.xCoord()) > 1)
	rightForce = -1.0 / (xPanelSize - absRightPosition.xCoord());

if ((absLeftPosition.xCoord()) > 1)
	leftForce = 1.0 / (absLeftPosition.xCoord());

if ((absUpPosition.yCoord()) > 1)
	topForce = 1.0 / (absUpPosition.yCoord());

if ((yPanelSize - absDownPosition.yCoord()) > 1)
	bottonForce = -1.0 / (yPanelSize - absDownPosition.yCoord());


glVector retval(rightForce+leftForce, topForce+bottonForce);

return retval;
