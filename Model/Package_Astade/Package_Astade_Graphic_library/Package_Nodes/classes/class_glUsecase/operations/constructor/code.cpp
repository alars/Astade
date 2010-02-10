Refresh();
AddMenuSeparator();
AddMenuFunction("specializes ...",wxCommandEventHandler(glUsecase::OnSpecializes));
AddMenuFunction("extends ...",wxCommandEventHandler(glUsecase::OnExtends));
AddMenuFunction("includes ...",wxCommandEventHandler(glUsecase::OnIncludes));
