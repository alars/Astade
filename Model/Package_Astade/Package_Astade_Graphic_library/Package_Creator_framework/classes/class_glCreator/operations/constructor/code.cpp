//~~ glCreator(wxString classname) [glCreator] ~~

objectList[classname] = this;

if (myClassMenu != NULL)
{
    int anID = glUniqueID::getID();
    idList[anID] = this;
    myClassMenu->Append(anID, wxS("new ") + classname, wxEmptyString, wxITEM_NORMAL);
}
