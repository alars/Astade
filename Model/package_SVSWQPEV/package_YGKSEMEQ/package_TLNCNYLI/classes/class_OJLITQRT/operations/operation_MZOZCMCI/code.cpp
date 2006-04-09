/* vi: set tabstop=4: */

wxPoint aPoint = ScreenToClient(event.GetPosition());
wxTextCoord line;
HitTest(aPoint,NULL,&line);
wxString theLine = GetLineText(line);

if (ParseTextline(theLine))
{
	wxMenu* aPopUp = new wxMenu("");
	aPopUp->Append(ID_EDIT_ERROR,"Open file","", wxITEM_NORMAL);
	PopupMenu(aPopUp);
	delete aPopUp;
}