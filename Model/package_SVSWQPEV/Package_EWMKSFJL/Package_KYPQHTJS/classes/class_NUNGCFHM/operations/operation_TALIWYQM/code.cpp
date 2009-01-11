return glVector();

/*
glVector absPosition = my_relPosition + myFloatingItem.absGetPosition();

double rightForce = -1;
double leftForce = 1;
double topForce = 1;
double bottonForce = -1;


if ((width - absPosition.xCoord() - my_Radius) > 1)
	rightForce = -1 / (width - absPosition.xCoord() - my_Radius);

if ((absPosition.xCoord() - my_Radius) > 1)
	leftForce = 1 / (absPosition.xCoord() - my_Radius);

if ((absPosition.yCoord() - my_Radius) > 1)
	topForce = 1 / (absPosition.yCoord() - my_Radius);

if ((height - absPosition.yCoord() - my_Radius) > 1)
	bottonForce = -1 / (height - absPosition.yCoord() - my_Radius);

return glVector(rightForce+leftForce, topForce+bottonForce);
*/