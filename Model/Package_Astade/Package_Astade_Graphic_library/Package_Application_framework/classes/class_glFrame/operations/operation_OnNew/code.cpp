//~~ void OnNew(wxCommandEvent& event) [glFrame] ~~

if (isChanged)
{
	int answer = wxMessageDialog(this, wxS("You made changes. Save?"), wxS("Save Changes?"), wxCANCEL | wxYES | wxNO | wxICON_QUESTION).ShowModal();

	if (answer == wxID_YES)
		Save();

	if (answer == wxID_CANCEL)
		return;
}

glGraphicElement::DestroyAll();
currentFile.clear();
isChanged = true;
SetTitle(wxS("*"));
graphicPanel->Refresh();
