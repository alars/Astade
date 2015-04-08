//~~ void AddMenuFunction(const wxString& item, wxObjectEventFunction function) [glGraphicElement] ~~

int id = glUniqueID::getID();
myContextMenu.Insert(0, id, item);
Connect(id, wxEVT_COMMAND_MENU_SELECTED, function);
