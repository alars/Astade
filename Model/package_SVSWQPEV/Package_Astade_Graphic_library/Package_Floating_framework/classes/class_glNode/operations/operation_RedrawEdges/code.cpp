for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); it++)
	(*it)->Redraw();
	
for (std::set<glSelfEdge*>::iterator it = mySelfEdges.begin(); it != mySelfEdges.end(); it++)
	(*it)->Refresh();
