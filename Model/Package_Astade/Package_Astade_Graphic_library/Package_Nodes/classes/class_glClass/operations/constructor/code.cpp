//~~ glClass(glGraphicPanel* parent, long x, long y) [glClass] ~~

Refresh();
AddMenuSeparator();
AddMenuFunction(wxS("start relation to"), wxCommandEventHandler(glClass::OnRelation));
AddMenuSeparator();
AddMenuFunction(wxS("toggle active"), wxCommandEventHandler(glClass::OnActive));
