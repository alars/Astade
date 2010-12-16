//~~ void OnRightMouseClick(wxEvent& event) [AstadeStatusBar] ~~

wxMenu* aPopUp = new wxMenu(wxEmptyString);

aPopUp->Append(ID_COPYSTATUS, "Copy absolute", "Copies the status-text to the clipboard");
aPopUp->Append(ID_COPYSTATUS_RELATIVE, "Copy relative", "Copies the status-text to the clipboard");
PopupMenu(aPopUp);    //From wxWindow::
delete aPopUp;
