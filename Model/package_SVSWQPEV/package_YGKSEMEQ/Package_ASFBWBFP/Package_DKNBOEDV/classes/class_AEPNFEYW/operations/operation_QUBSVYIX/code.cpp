for (std::set<GrafNodeCreator*>::iterator it = myGrafNodeCreator.begin();it != myGrafNodeCreator.end(); it++)
	if ((*it)->GetClassName()==className)
		return &((*it)->Create(parent,pos));

return 0;