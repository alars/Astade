//~~ void Open() [glFrame] ~~
if (isChanged)
{
	int answer = wxMessageDialog(this, wxS("You made changes. Save?"), wxS("Save Changes?"), wxCANCEL | wxYES | wxNO | wxICON_QUESTION).ShowModal();

	if (answer == wxID_YES)
		Save();

	if (answer == wxID_CANCEL)
		return;
}

const wxString& file = wxFileSelector(wxS("File to open"), wxEmptyString, wxEmptyString, wxEmptyString, wxS("*"), 0, this);
Load(file);
