/* vi: set tabstop=4: */

wxPoint aPoint = ScreenToClient(event.GetPosition());
wxTextCoord line;
HitTest(aPoint,NULL,&line);
wxString theLine = GetLineText(line);

if (ParseTextline(theLine))
{
	char buffer[30];
	sprintf(buffer,"line:%d",static_cast<int>(line));
	wxMenu* aPopUp = new wxMenu(buffer);
	aPopUp->Append(6776,"Open file","", wxITEM_NORMAL);
	PopupMenu(aPopUp);
	delete aPopUp;
}