glVector forceSum;

for (std::set<glGravityArea*>::iterator it = objectList.begin(); it != objectList.end(); it++)
{
	if ((*it) != this)
	{
		glVector myBorder = (*it)->absCalculateNearestToArea(this);
		glVector itBorder = absCalculateNearestToArea(*it);

		glVector direction = (itBorder - myBorder);
		double disance = direction.Mod();

		glVector help = direction.Dir();
		help *= 1.0 / (disance*disance);

		forceSum += help;
	}
}

forceSum *= 60;

return forceSum;