wxMenu* aPopUp = new wxMenu(wxEmptyString);

aPopUp->Append(ID_COPYSTATUS, "Copy", "Copies the status-text to the clipboard");
PopupMenu(aPopUp);    //From wxWindow::
delete aPopUp;
