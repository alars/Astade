for (std::set<GrafArrow*>::iterator it = mySuperclass.begin(); it != mySuperclass.end(); it++)
{
	GrafVector resultingForce = (*it)->GetForce();
	m_force += resultingForce;
	(*it)->GetEndNode().m_force -= resultingForce;
}

for (std::set<GrafArrow*>::iterator it = myAssociation.begin(); it != myAssociation.end(); it++)
{
	GrafVector resultingForce = (*it)->GetForce();
	m_force += resultingForce;
	(*it)->GetEndNode().m_force -= resultingForce;
}

GrafNode::CalculatePosition();