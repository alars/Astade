objectList[classname] = this;

if (myClassMenu != NULL)
{
    int aID = glUniqeID::getID();
    idList[aID] = this;
    myClassMenu->Append(aID,"new "+classname,"", wxITEM_NORMAL);
}
