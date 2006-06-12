wxMenu* aPopUp = new wxMenu(wxEmptyString);

aPopUp->Append(generalisationID,"generalizes ...",wxEmptyString, wxITEM_NORMAL);
aPopUp->Append(extendID,"extends ...",wxEmptyString, wxITEM_NORMAL);
aPopUp->Append(includeID,"includes ...",wxEmptyString, wxITEM_NORMAL);
aPopUp->AppendSeparator();
aPopUp->Append(deleteID,"delete",wxEmptyString, wxITEM_NORMAL);

PopupMenu(aPopUp);
delete aPopUp;