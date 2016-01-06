//~~ glSimpleBox(glGraphicPanel* parent, long x, long y) [glSimpleBox] ~~

Refresh();
AddMenuSeparator();
AddMenuFunction(wxS("edge"), wxCommandEventHandler(glSimpleBox::OnCreateEdge));
AddMenuFunction(wxS("round edge"), wxCommandEventHandler(glSimpleBox::OnCreateSplinedEdge));
AddMenuFunction(wxS("combined edge"), wxCommandEventHandler(glSimpleBox::OnCreateCombinedEdge));
