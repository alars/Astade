glVector forceSum;

for (std::set<glGravityArea*>::iterator it = objectList.begin(); it != objectList.end(); it++)
{
	if ((*it) != this)
	{
	  forceSum += (*it)->GetForceFromArea(*this);
	}
}

return forceSum;
