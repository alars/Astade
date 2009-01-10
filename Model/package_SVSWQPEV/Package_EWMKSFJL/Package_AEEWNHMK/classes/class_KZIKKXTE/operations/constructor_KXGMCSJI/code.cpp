objectList[classname] = this;
int aID = glUniqeID::getID();
idList[aID] = this;
myClassMenu.Append(aID,classname,"", wxITEM_NORMAL);