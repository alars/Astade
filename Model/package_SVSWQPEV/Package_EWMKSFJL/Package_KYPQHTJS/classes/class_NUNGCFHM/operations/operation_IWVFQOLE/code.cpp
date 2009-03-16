glVector forceSum;

for (std::set<glGravityArea*>::iterator it = objectList.begin(); it != objectList.end(); it++)
{
	if ((*it) != this)
	{
		glVector myBorder = (*it)->absGetBorderPoint(absGetPosition());
		glVector itBorder = absGetBorderPoint((*it)->absGetPosition());
		double disance = (itBorder - myBorder).Mod();

		glVector direction = (*it)->GetBorderDirection(absGetPosition());

		direction *= (1.0 / (disance*disance));
		forceSum += direction;
	}
}

forceSum *= 60;

return forceSum;