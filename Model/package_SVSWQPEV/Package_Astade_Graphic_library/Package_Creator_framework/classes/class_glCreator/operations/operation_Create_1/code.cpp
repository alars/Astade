if (objectList.find(classname) != objectList.end())
	return objectList[classname]->Create(parent,x,y);
else
	return NULL;
