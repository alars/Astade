wxMenu* aPopUp = new wxMenu(wxEmptyString);

aPopUp->Append(generalisationID,"specializes ...",wxEmptyString, wxITEM_NORMAL);
aPopUp->Append(extendID,"extends ...",wxEmptyString, wxITEM_NORMAL);
aPopUp->Append(includeID,"includes ...",wxEmptyString, wxITEM_NORMAL);
aPopUp->AppendSeparator();
aPopUp->Append(-1,"delete",CreateDeleteMenu());

PopupMenu(aPopUp);
delete aPopUp;