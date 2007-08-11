aPopUp.Append(ID_PASTE,"paste",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
aPopUp.Append(ID_ADDATTRIBUTE,"add attribute",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
aPopUp.Append(ID_DELETE,"delete from Model",wxEmptyString, wxITEM_NORMAL);

aPopUp.Enable(ID_PASTE, OfferPaste());