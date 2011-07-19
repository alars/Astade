//~~ void Open() [glFrame] ~~
if (isChanged)
{
	int answere = wxMessageDialog(this,"You made changes. Save?","Save Changes?",wxCANCEL | wxYES | wxNO | wxICON_QUESTION).ShowModal();

	wxCommandEvent anEvent;

	if (answere==wxID_YES)
		Save();

	if (answere==wxID_CANCEL)
		return;
}

const wxString& file = wxFileSelector("File to open","","","","*",0,this);
Load(file);
