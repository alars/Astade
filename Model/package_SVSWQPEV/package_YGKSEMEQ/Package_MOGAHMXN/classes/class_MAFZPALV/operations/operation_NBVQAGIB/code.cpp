aPopUp.Append(ID_FEATURES,"features",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
aPopUp.Append(ID_ADDTRANSITION,"add transition",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
aPopUp.Append(ID_PASTE,"paste",wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_COPY,"copy",wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_CUT,"cut",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
aPopUp.Append(ID_DELETE,"delete from Model",wxEmptyString, wxITEM_NORMAL);

aPopUp.Enable(ID_PASTE, OfferPaste());