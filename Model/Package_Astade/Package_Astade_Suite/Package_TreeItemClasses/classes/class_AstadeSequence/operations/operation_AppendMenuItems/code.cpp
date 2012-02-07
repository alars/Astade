//~~ void AppendMenuItems(wxMenu& aPopUp) [AstadeSequence] ~~

aPopUp.Append(ID_EDIT, wxS("edit"), wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
AppendCutnPaste(aPopUp, COPY_SOURCE);
aPopUp.AppendSeparator();
aPopUp.Append(ID_DELETE, wxS("delete"), wxEmptyString, wxITEM_NORMAL);
