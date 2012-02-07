//~~ void AppendMenuItems(wxMenu& aPopUp) [AstadeSequences] ~~

aPopUp.Append(ID_ADDSEQUENCEDIAGRAM, wxS("add sequence diagram"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
AppendCutnPaste(aPopUp, COPY_TARGET);
aPopUp.AppendSeparator();
aPopUp.Append(ID_DELETE, wxS("delete from Model"), wxEmptyString, wxITEM_NORMAL);
