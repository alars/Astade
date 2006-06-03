for (std::list<GrafNode*>::iterator it = myGrafNodes.begin(); it != myGrafNodes.end(); it++)
{
	GrafVector g = (*it)->GetPosition();
	(*it)->OnDraw(dc);
}