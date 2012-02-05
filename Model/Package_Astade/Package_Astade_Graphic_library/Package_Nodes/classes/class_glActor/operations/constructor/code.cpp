//~~ glActor(glGraphicPanel* parent, long x, long y) [glActor] ~~

Refresh();
AddMenuSeparator();
AddMenuFunction(wxS("Association to ..."), wxCommandEventHandler(glActor::OnCreateEdge));
AddMenuFunction(wxS("specializes..."), wxCommandEventHandler(glActor::OnSpecializes));
