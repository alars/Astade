Refresh();
AddMenuSeparator();
AddMenuFunction("specializes ...",wxCommandEventHandler(glUsecase::OnExtends));
AddMenuFunction("extends ...",wxCommandEventHandler(glUsecase::OnExtends));
AddMenuFunction("includes ...",wxCommandEventHandler(glUsecase::OnIncludes));
