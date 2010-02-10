Refresh();
AddMenuSeparator();
AddMenuFunction("Association to ...",wxCommandEventHandler(glActor::OnCreateEdge));
AddMenuFunction("specializes...",wxCommandEventHandler(glActor::OnSpecializes));

