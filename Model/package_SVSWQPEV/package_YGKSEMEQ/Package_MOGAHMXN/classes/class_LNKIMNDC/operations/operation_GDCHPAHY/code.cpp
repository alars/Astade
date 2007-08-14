AppendCutnPaste(aPopUp, COPY_TARGET);
aPopUp.AppendSeparator();
aPopUp.Append(ID_ADDOPERATION,"add operation",wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_ADDCONSTRUCTOR,"add constructor",wxEmptyString, wxITEM_NORMAL);
aPopUp.Append(ID_ADDDESTRUCTOR,"add destructor",wxEmptyString, wxITEM_NORMAL);
aPopUp.AppendSeparator();
aPopUp.Append(ID_DELETE,"delete from Model",wxEmptyString, wxITEM_NORMAL);

if (dynamic_cast<AdeDirectoryElement*>(myModelElement)->GetHasDestructor())
	aPopUp.Enable(ID_ADDDESTRUCTOR, false);
