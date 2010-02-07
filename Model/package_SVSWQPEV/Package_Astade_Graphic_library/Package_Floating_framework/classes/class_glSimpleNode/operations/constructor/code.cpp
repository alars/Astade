Refresh();
AddMenuSeparator();
AddMenuFunction("edge",wxCommandEventHandler(glSimpleNode::OnCreateEdge));
AddMenuFunction("round edge",wxCommandEventHandler(glSimpleNode::OnCreateSplinedEdge));

