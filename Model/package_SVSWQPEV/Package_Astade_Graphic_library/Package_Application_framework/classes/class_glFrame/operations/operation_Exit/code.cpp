if (isChanged)
{
	int answere = wxMessageDialog(this,"You made changes. Save?","Save Changes?",wxCANCEL | wxYES | wxNO | wxICON_QUESTION).ShowModal();

	wxCommandEvent anEvent;

	if (answere==wxID_YES)
		Save();

	return (answere!=wxID_CANCEL);
}
else
	return true;
