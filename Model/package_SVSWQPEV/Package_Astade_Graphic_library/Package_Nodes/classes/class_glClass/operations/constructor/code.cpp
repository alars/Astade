Refresh();
AddMenuSeparator();
AddMenuFunction("start relation to",wxCommandEventHandler(glClass::OnRelation));
AddMenuSeparator();
AddMenuFunction("toggle active",wxCommandEventHandler(glClass::OnActive));
