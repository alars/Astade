//~~ void ContextMenu(wxContextMenuEvent& event) [AstadeMakeOutputEdit] ~~

wxPoint aPoint = ScreenToClient(event.GetPosition());
wxTextCoord dummy, line;
HitTest(aPoint, &dummy, &line);
wxString theLine(GetLineText(line));

if (ParseTextline(theLine))
{
	wxMenu* aPopUp = new wxMenu(wxEmptyString);
	aPopUp->Append(ID_EDIT_ERROR, wxS("Open file"), wxEmptyString, wxITEM_NORMAL);
	if (FindModelElement())
		aPopUp->Append(ID_EDIT_ERROR_ELEMENT, wxS("Open model element"), wxEmptyString, wxITEM_NORMAL);
	PopupMenu(aPopUp);
	delete aPopUp;
}
