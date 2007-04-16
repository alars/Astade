int index = event.GetId() - ID_EDITBEGIN;

dataBase->DeleteClass(index);
isChanged = true;
delete myEditMenu->Remove(event.GetId());

Refresh();