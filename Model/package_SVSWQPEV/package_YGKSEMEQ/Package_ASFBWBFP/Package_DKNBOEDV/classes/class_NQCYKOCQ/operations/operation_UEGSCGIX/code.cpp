//m_force += GrafVector(-0.1,0);

for (std::set<GrafUseCase*>::iterator it = myGrafUseCase.begin(); it != myGrafUseCase.end(); it++)
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