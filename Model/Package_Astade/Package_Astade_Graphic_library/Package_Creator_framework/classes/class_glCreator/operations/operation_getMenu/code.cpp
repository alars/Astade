//~~ wxMenu* getMenu() [glCreator] ~~

if (myClassMenu == NULL)
{
	myClassMenu = new wxMenu;
    for (std::map<wxString, glCreator*>::iterator it = objectList.begin(); it != objectList.end(); ++it)
    {
        int anID = glUniqueID::getID();
        idList[anID] = (*it).second;
        myClassMenu->Append(anID, wxS("new ") + (*it).first, wxEmptyString, wxITEM_NORMAL);
    }
}
return myClassMenu;
