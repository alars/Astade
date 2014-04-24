int eventID = dataBase->GetEventID(mouseOverEvent);

wxMenu* aPopUp =  new wxMenu("");

switch (eventID)
{
	default:
		delete aPopUp;
		return;
	break;
}

wxWindow aWindow(this,-1,wxPoint(0,0),wxSize(0,0));
aWindow.PopupMenu(aPopUp);
delete aPopUp;
