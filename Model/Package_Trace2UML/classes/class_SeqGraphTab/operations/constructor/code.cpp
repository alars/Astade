//~~ SeqGraphTab(wxWindow* parent, SeqDataBase* theDataBase) [SeqGraphTab] ~~
if (parent)
{
	SetScrollbars(20, 20, 50, 50);
	myToolTip = new wxToolTip(wxEmptyString);
	SetToolTip(myToolTip);
}
SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
