//~~ wxMenu* getMenu() [glCreator] ~~

if (myClassMenu == NULL)
{
	myClassMenu = new wxMenu;
    for (std::map<wxString, glCreator*>::iterator it = objectList.begin(); it != objectList.end(); it++)
    {
        int anID = glUniqeID::getID();
        idList[anID] = (*it).second;
        myClassMenu->Append(anID, "new " + (*it).first, "", wxITEM_NORMAL);
    }
}
return myClassMenu;
