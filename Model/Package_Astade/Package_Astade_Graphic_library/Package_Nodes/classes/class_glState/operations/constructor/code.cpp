//~~ glState(glGraphicPanel* parent, long x, long y) [glState] ~~

Refresh();
AddMenuSeparator();
AddMenuFunction(wxS("transition"), wxCommandEventHandler(glState::OnCreateEdge));
