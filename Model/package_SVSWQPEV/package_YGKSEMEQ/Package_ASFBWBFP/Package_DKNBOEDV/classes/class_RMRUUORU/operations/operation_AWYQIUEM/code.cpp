for (std::set<GrafArrow*>::iterator it = mySuperclass.begin(); it != mySuperclass.end(); it++)
{
	GrafVector resultingForce = (*it)->GetForce();
	m_force += resultingForce;
	(*it)->GetEndNode().m_force -= resultingForce;
}

for (std::set<GrafArrow*>::iterator it = myExtend.begin(); it != myExtend.end(); it++)
{
	GrafVector resultingForce = (*it)->GetForce();
	m_force += resultingForce;
	(*it)->GetEndNode().m_force -= resultingForce;
}

for (std::set<GrafArrow*>::iterator it = myInclude.begin(); it != myInclude.end(); it++)
{
	GrafVector resultingForce = (*it)->GetForce();
	m_force += resultingForce;
	(*it)->GetEndNode().m_force -= resultingForce;
}

GrafNode::CalculatePosition();