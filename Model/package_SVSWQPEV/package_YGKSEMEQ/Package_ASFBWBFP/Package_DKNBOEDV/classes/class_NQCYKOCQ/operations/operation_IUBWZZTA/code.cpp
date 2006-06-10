wxMenu* aPopUp = new wxMenu(wxEmptyString);

aPopUp->Append(featuresID,"features",wxEmptyString, wxITEM_NORMAL);
aPopUp->Append(hasAssociationID,"Association to ...",wxEmptyString, wxITEM_NORMAL);
aPopUp->AppendSeparator();
aPopUp->Append(deleteID,"delete",wxEmptyString, wxITEM_NORMAL);

PopupMenu(aPopUp);
delete aPopUp;