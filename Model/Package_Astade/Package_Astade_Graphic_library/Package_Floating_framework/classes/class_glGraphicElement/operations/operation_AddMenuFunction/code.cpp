int id = glUniqeID::getID();
myContextMenu.Insert(0,id,item);
Connect(id, wxEVT_COMMAND_MENU_SELECTED,function);