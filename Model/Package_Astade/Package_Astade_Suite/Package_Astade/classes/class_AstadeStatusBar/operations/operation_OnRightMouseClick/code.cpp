//~~ void OnRightMouseClick(wxEvent& event) [AstadeStatusBar] ~~

wxMenu* aPopUp = new wxMenu(wxEmptyString);

aPopUp->Append(ID_COPYSTATUS, wxS("Copy absolute"), wxS("Copies the status-text to the clipboard"));
aPopUp->Append(ID_COPYSTATUS_RELATIVE, wxS("Copy relative"), wxS("Copies the status-text to the clipboard"));
PopupMenu(aPopUp);    //From wxWindow::
delete aPopUp;
