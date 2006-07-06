for (std::set<GrafArrow*>::iterator it = myEdges.begin(); it != myEdges.end(); it++)
	(*it)->NotifyDelete(node);