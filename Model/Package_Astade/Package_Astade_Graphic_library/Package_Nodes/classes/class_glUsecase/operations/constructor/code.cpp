//~~ glUsecase(glGraphicPanel* parent, long x, long y) [glUsecase] ~~

Refresh();
AddMenuSeparator();
AddMenuFunction(wxS("specializes ..."), wxCommandEventHandler(glUsecase::OnSpecializes));
AddMenuFunction(wxS("extends ..."), wxCommandEventHandler(glUsecase::OnExtends));
AddMenuFunction(wxS("includes ..."), wxCommandEventHandler(glUsecase::OnIncludes));
