if (textTab->IsModified())
{
	int answer = wxMessageDialog(this, _T("You made changes. Save?"), _T("Save Changes?"), wxCANCEL | wxYES | wxNO | wxICON_QUESTION).ShowModal();

	wxCommandEvent anEvent;

	if (answer == wxID_YES)
		Save(anEvent);

	if (answer != wxID_CANCEL)
		event.Skip();
}
else
	event.Skip();
