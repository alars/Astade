glVector absPosition = absGetPosition();

double rightForce = -0.2;
double leftForce = 0.2;
double topForce = 0.2;
double bottonForce = -0.2;


if ((width - absPosition.xCoord() - my_Radius) > 1)
	rightForce = -0.1 / (width - absPosition.xCoord() - my_Radius);

if ((absPosition.xCoord() - my_Radius) > 1)
	leftForce = 0.1 / (absPosition.xCoord() - my_Radius);

if ((absPosition.yCoord() - my_Radius) > 1)
	topForce = 0.1 / (absPosition.yCoord() - my_Radius);

if ((height - absPosition.yCoord() - my_Radius) > 1)
	bottonForce = -0.1 / (height - absPosition.yCoord() - my_Radius);


return glVector(rightForce+leftForce, topForce+bottonForce);