//m_force += GrafVector(-0.1,0);

for (std::set<GrafNode*>::iterator it = myAssociation.begin(); it != myAssociation.end(); it++)
{
	GrafVector p1 = GetPosition();
	GrafVector p2 = (*it)->GetPosition();

	GrafVector dif = p2-p1;
	double dist = dif.Mod();
	GrafVector resultingForce;

	resultingForce = dif.Dir() * dist * dist / (1000000);

	m_force += resultingForce;
	(*it)->m_force -= resultingForce;
}

return GrafNode::CalculatePosition();