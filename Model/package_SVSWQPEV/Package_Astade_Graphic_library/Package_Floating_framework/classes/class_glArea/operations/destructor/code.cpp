objectList.erase(this);

for (std::set<glArea*>::iterator it = objectList.begin(); it != objectList.end(); it++)
	(*it)->NotifyDelete(this);