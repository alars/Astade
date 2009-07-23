Refresh();
AddMenuSeparator();
AddMenuFunction("edge",wxCommandEventHandler(glSimpleNode::OnCreateEdge));
AddMenuFunction("splined edge",wxCommandEventHandler(glSimpleNode::OnCreateSplinedEdge));

