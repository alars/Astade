//~~ glSimpleOval(glGraphicPanel* parent, long x, long y) [glSimpleOval] ~~

Refresh();
AddMenuSeparator();
AddMenuFunction(wxS("edge"), wxCommandEventHandler(glSimpleOval::OnCreateEdge));
