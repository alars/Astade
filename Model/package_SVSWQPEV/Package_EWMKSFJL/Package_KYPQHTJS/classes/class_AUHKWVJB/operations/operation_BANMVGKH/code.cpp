AddPosition(absTo - absFrom);

for (std::set<glSelfEdge*>::iterator it = mySelfEdges.begin(); it != mySelfEdges.end(); it++)
	(*it)->AddPosition(absTo - absFrom);

RedrawEdges();
