glVector absPosition = absGetCenterPoint();

double rightForce = -1;
double leftForce = 1;
double topForce = 1;
double bottonForce = -1;


if ((width - absPosition.xCoord() - my_Radius) > 1)
	rightForce = -1.0 / (width - absPosition.xCoord() - my_Radius);

if ((absPosition.xCoord() - my_Radius) > 1)
	leftForce = 1.0 / (absPosition.xCoord() - my_Radius);

if ((absPosition.yCoord() - my_Radius) > 1)
	topForce = 1.0 / (absPosition.yCoord() - my_Radius);

if ((height - absPosition.yCoord() - my_Radius) > 1)
	bottonForce = -1.0 / (height - absPosition.yCoord() - my_Radius);


glVector retval(rightForce+leftForce, topForce+bottonForce);

return retval;