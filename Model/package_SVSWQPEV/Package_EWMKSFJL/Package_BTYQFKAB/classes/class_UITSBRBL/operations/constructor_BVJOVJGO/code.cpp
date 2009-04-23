Refresh();
AddMenuSeparator();
AddMenuFunction("specializes ...",wxCommandEventHandler(glUsecase::OnCreateEdge));
AddMenuFunction("extends ...",wxCommandEventHandler(glUsecase::OnCreateEdge));
AddMenuFunction("includes ...",wxCommandEventHandler(glUsecase::OnIncludes));
