//~~ void AppendMenuItems(wxMenu& aPopUp) [AstadeModel] ~~

aPopUp.Append(ID_ADDCOMPONENTFOLDER, wxS("add component folder"), wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_ADDPACKAGE, wxS("add package"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
AppendCutnPaste(aPopUp, COPY_TARGET);
aPopUp.AppendSeparator();
aPopUp.Append(-1, wxS("select repository"), CreateRepositoryMenu());
