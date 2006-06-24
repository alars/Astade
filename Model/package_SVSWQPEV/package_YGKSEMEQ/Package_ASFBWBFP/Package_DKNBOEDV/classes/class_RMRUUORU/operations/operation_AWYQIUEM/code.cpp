//m_force += GrafVector(0.001,0.0001);

for (std::set<GrafArrow>::iterator it = mySuperclass.begin(); it != mySuperclass.end(); it++)
{
	GrafVector p1 = GetPosition();
	GrafVector p2 = (*it).GetEndNode().GetPosition();

	GrafVector dif = p2-p1;
	double dist = dif.Mod2();
	GrafVector resultingForce;

	resultingForce = dif.Dir() * dist / (1000000);

	m_force += resultingForce;
	(*it).GetEndNode().m_force -= resultingForce;
}

for (std::set<GrafArrow>::iterator it = myExtend.begin(); it != myExtend.end(); it++)
{
	GrafVector p1 = GetPosition();
	GrafVector p2 = (*it).GetEndNode().GetPosition();

	GrafVector dif = p2-p1;
	double dist = dif.Mod2();
	GrafVector resultingForce;

	resultingForce = dif.Dir() * dist / (1000000);

	m_force += resultingForce;
	(*it).GetEndNode().m_force -= resultingForce;
}

for (std::set<GrafArrow>::iterator it = myInclude.begin(); it != myInclude.end(); it++)
{
	GrafVector p1 = GetPosition();
	GrafVector p2 = (*it).GetEndNode().GetPosition();

	GrafVector dif = p2-p1;
	double dist = dif.Mod2();
	GrafVector resultingForce;

	resultingForce = dif.Dir() * dist / (1000000);

	m_force += resultingForce;
	(*it).GetEndNode().m_force -= resultingForce;
}

return GrafNode::CalculatePosition();