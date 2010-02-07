destroyList.clear();
while (objectList.begin() != objectList.end())
	delete (*objectList.begin());
