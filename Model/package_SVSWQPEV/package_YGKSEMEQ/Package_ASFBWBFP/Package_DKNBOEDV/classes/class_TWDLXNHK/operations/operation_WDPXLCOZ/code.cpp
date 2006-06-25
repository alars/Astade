
int width,hight;
GetSize(&width,&hight);

double right_force = 1;
if ((-position.xCoord()+width)>0.1)
	right_force = 1.0/(-position.xCoord()+width);

double left_force = -1;
if (position.xCoord()>0.1)
	left_force = -1.0/position.xCoord();

double floor_force = 1;
if ((-position.yCoord()+hight)>0.1)
	floor_force = 1.0/(-position.yCoord()+hight);

double top_force = -1;
if (position.yCoord()>0.1)
	top_force = 1.0/-(position.yCoord());

GrafVector force(0,-top_force);
force += GrafVector(0,-floor_force);
force += GrafVector(-right_force,0);
force += GrafVector(-left_force,0);

if (force.Mod2() > 1)
	force = force.Dir();

for (std::set<GrafNode*>::const_iterator it = GetGrafNodes().begin(); it != GetGrafNodes().end(); it++)
{
	if (exeptions.find(*it) == exeptions.end())
	{
		GrafVector r1 = (*it)->GetBorderPoint(position);
		GrafVector r2 = position;

		GrafVector dif = r2-r1;
		double dist = dif.Mod();
		GrafVector resultingForce;

		if ((*it)->IsInArea(r2))
			resultingForce = dif.Dir();
		else
			resultingForce = dif.Dir() / (dist);

		if (resultingForce.Mod2() > 1)
			resultingForce = dif.Dir();

		force += resultingForce;
	}
}

return force;
