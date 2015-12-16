//~~ glSimpleNode(glGraphicPanel* parent, long x, long y) [glSimpleNode] ~~

Refresh();
AddMenuSeparator();
AddMenuFunction(wxS("edge"), wxCommandEventHandler(glSimpleNode::OnCreateEdge));
AddMenuFunction(wxS("round edge"), wxCommandEventHandler(glSimpleNode::OnCreateSplinedEdge));
AddMenuFunction(wxS("combined edge"), wxCommandEventHandler(glSimpleNode::OnCreateCombinedEdge));
