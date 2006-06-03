static double movementCounter = 0;

for (std::list<GrafNode*>::iterator it = myGrafNodes.begin(); it != myGrafNodes.end(); it++)
{
	movementCounter += (*it)->CalculatePosition();
}

if (movementCounter > 3)
{
	Refresh();
	movementCounter = 0;
}