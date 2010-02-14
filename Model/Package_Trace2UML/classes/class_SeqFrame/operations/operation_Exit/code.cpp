if (textTab->IsModified())
{
	int answer = wxMessageDialog(this, wxS("You made changes. Save?"), wxS("Save Changes?"), wxCANCEL | wxYES | wxNO | wxICON_QUESTION).ShowModal();

	wxCommandEvent anEvent;

	if (answer == wxID_YES)
		Save(anEvent);

	if (answer != wxID_CANCEL)
		event.Skip();
}
else
	event.Skip();
