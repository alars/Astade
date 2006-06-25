for (std::set<GrafArrow*>::iterator it = myAssociation.begin(); it != myAssociation.end(); it++)
{
	GrafVector resultingForce = (*it)->GetForce();
	m_force += resultingForce;
	(*it)->GetEndNode().m_force -= resultingForce;
}

return GrafNode::CalculatePosition();