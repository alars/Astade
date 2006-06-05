MouseInWindow = false;

for (std::list<GrafNode*>::iterator it = myGrafNodes.begin(); it != myGrafNodes.end(); it++)
	(*it)->m_MouseOver = false;

Refresh();