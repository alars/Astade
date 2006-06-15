wxMenu* aPopUp = new wxMenu(wxEmptyString);

aPopUp->Append(hasAssociationID,"Association to ...",wxEmptyString, wxITEM_NORMAL);
aPopUp->AppendSeparator();
aPopUp->Append(-1,"delete",CreateDeleteMenu());

PopupMenu(aPopUp);
delete aPopUp;