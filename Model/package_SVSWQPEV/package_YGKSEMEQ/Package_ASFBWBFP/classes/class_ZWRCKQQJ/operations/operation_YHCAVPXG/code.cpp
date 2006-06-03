wxMenu* aPopUp = new wxMenu(wxEmptyString);

aPopUp->Append(ID_ADDACTOR,"new actor",wxEmptyString, wxITEM_NORMAL);
aPopUp->Append(ID_ADDUSECASE,"new usecase",wxEmptyString, wxITEM_NORMAL);

PopupMenu(aPopUp);
delete aPopUp;