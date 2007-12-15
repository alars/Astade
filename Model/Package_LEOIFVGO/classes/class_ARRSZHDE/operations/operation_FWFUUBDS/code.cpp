if (textTab->IsModified())
{
	int answer = wxMessageDialog(this, _T("You made changes. Save?"), _T("Save Changes?"), wxCANCEL | wxYES | wxNO | wxICON_QUESTION).ShowModal();

	wxCommandEvent anEvent;

	if (answer == wxID_YES)
		Save(anEvent);

	if (answer == wxID_CANCEL)
		return;
}

const wxString& dir = wxFileSelector(_T("File to open"), _T(""), _T(""), _T(""), _T("*.seq"), 0, this);
Load(dir);
