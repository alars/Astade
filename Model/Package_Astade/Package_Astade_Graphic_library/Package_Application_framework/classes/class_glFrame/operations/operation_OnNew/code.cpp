if (isChanged)
{
	int answere = wxMessageDialog(this,"You made changes. Save?","Save Changes?",wxCANCEL | wxYES | wxNO | wxICON_QUESTION).ShowModal();

	wxCommandEvent anEvent;

	if (answere==wxID_YES)
		Save();

	if (answere==wxID_CANCEL)
		return;
}

glGraphicElement::DestroyAll();
currentFile.clear();
isChanged = true;
SetTitle(wxString("*"));
graphicPanel->Refresh();
