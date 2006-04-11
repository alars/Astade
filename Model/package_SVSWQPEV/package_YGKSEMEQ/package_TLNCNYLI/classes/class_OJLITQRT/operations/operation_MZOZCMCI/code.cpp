/* vi: set tabstop=4: */

wxPoint aPoint = ScreenToClient(event.GetPosition());
wxTextCoord dummy, line;
HitTest(aPoint, &dummy, &line);
wxString theLine(GetLineText(line));

if (ParseTextline(theLine))
{
	wxMenu* aPopUp = new wxMenu(wxEmptyString);
	aPopUp->Append(ID_EDIT_ERROR, "Open file", wxEmptyString, wxITEM_NORMAL);
	PopupMenu(aPopUp);
	delete aPopUp;
}
