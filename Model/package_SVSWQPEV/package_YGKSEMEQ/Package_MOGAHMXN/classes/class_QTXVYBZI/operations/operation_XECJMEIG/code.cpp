aPopUp.Append(ID_ADDCOMPONENTFOLDER,"add component folder",wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_ADDPACKAGE,"add package",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
aPopUp.Append(ID_PASTE,"paste",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
aPopUp.Append(-1,"select repository",CreateRepositoryMenu());

aPopUp.Enable(ID_PASTE, OfferPaste());
