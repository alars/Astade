wxMenu* aPopUp = new wxMenu(wxEmptyString);

aPopUp->Append(ID_COPYSTATUS, "Copy Statustext", "Copys the statustext to the clipboard.");

PopupMenu(aPopUp);    //From wxWindow::
delete aPopUp;
