int index = event.GetId() - ID_EDITBEGIN;

dataBase->DeleteClass(index);
isChanged = true;

Refresh();