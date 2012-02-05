//~~ glCreator(wxString classname) [glCreator] ~~

objectList[classname] = this;

if (myClassMenu != NULL)
{
    int anID = glUniqeID::getID();
    idList[anID] = this;
    myClassMenu->Append(anID, wxS("new ") + classname, wxEmptyString, wxITEM_NORMAL);
}
