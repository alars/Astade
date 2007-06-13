for (std::list<ACNode*>::iterator it = myNodes.begin(); it != myNodes.end(); it++)
{
	(*it)->OnDraw(dc);
}