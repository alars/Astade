if (myClassMenu == NULL)
{
	myClassMenu = new wxMenu;
    for (std::map<wxString, glCreator*>::iterator it = objectList.begin(); it != objectList.end(); it++)
    {
        int aID = glUniqeID::getID();
        idList[aID] = (*it).second;
        myClassMenu->Append(aID,"new "+(*it).first,"", wxITEM_NORMAL);
    }
}
return myClassMenu;
