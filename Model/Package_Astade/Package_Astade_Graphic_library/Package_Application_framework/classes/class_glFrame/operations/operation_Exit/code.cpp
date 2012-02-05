//~~ bool Exit() [glFrame] ~~

if (isChanged)
{
	int answer = wxMessageDialog(this, wxS("You made changes. Save?"), wxS("Save Changes?"), wxCANCEL | wxYES | wxNO | wxICON_QUESTION).ShowModal();

	if (answer == wxID_YES)
		Save();

	return (answer != wxID_CANCEL);
}
else
	return true;
