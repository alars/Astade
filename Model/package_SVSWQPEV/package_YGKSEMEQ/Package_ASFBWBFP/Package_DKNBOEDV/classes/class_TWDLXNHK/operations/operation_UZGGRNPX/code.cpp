MouseInWindow = false;

for (std::set<GrafNode*>::iterator it = myGrafNodes.begin(); it != myGrafNodes.end(); it++)
	(*it)->m_MouseOver = false;

Refresh();