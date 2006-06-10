wxMenu* aPopUp = new wxMenu(wxEmptyString);

aPopUp->Append(deleteID,"delete",wxEmptyString, wxITEM_NORMAL);

PopupMenu(aPopUp);
delete aPopUp;