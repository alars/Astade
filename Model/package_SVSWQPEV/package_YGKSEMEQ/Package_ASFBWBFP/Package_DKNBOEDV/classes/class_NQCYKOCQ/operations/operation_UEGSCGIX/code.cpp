//m_force += GrafVector(-0.1,0);

for (std::set<GrafArrow>::iterator it = myAssociation.begin(); it != myAssociation.end(); it++)
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