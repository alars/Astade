//~~ glCreator(wxString classname) [glCreator] ~~

objectList[classname] = this;

if (myClassMenu != NULL)
{
    int anID = glUniqeID::getID();
    idList[anID] = this;
    myClassMenu->Append(anID, "new " + classname, "", wxITEM_NORMAL);
}
