//m_force += GrafVector(0.001,0.0001);

for (std::set<GrafNode*>::iterator it = mySuperclass.begin(); it != mySuperclass.end(); it++)
{
	GrafVector p1 = GetPosition();
	GrafVector p2 = (*it)->GetPosition();

	GrafVector dif = p2-p1;
	double dist = dif.Mod();
	GrafVector resultingForce;

	resultingForce = dif.Dir() * dist / 4000;

	m_force += resultingForce;
	(*it)->m_force -= resultingForce;
}

for (std::set<GrafNode*>::iterator it = myExtent.begin(); it != myExtent.end(); it++)
{
	GrafVector p1 = GetPosition();
	GrafVector p2 = (*it)->GetPosition();

	GrafVector dif = p2-p1;
	double dist = dif.Mod();
	GrafVector resultingForce;

	resultingForce = dif.Dir() * dist / 4000;

	m_force += resultingForce;
	(*it)->m_force -= resultingForce;
}

for (std::set<GrafNode*>::iterator it = myInclude.begin(); it != myInclude.end(); it++)
{
	GrafVector p1 = GetPosition();
	GrafVector p2 = (*it)->GetPosition();

	GrafVector dif = p2-p1;
	double dist = dif.Mod();
	GrafVector resultingForce;

	resultingForce = dif.Dir() * dist / 4000;

	m_force += resultingForce;
	(*it)->m_force -= resultingForce;
}

return GrafNode::CalculatePosition();