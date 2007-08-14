aPopUp.Append(ID_ADDCOMPONENTFOLDER,"add component folder",wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_ADDPACKAGE,"add package",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
AppendCutnPaste(aPopUp, COPY_TARGET);
aPopUp.AppendSeparator();
aPopUp.Append(-1,"select repository",CreateRepositoryMenu());
