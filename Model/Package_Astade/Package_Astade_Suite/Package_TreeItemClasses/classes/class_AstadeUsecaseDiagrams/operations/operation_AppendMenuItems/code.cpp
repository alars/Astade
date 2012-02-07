//~~ void AppendMenuItems(wxMenu& aPopUp) [AstadeUsecaseDiagrams] ~~

aPopUp.Append(ID_ADDUSECASEDIAGRAM, wxS("add use case diagram"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
AppendCutnPaste(aPopUp, COPY_TARGET);
aPopUp.AppendSeparator();
aPopUp.Append(ID_DELETE, wxS("delete from Model"), wxEmptyString, wxITEM_NORMAL);
