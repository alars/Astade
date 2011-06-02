//~~ void Copyfile(wxCommandEvent& event) [AstadeFrame] ~~

const wxString& dir = wxFileSelector("Select file", wxEmptyString, wxEmptyString, wxEmptyString, "*.*", 0, this);
if (dir.empty())
	return;

wxFileName filename(dir);

wxTreeItemId anID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(anID)->GetFileName();
parentPath.SetFullName(filename.GetFullName());

if (parentPath.FileExists())
{
	wxMessageDialog aDialog(this, "File already exists. Overwrite?", "Copy file:", wxOK | wxCANCEL | wxICON_EXCLAMATION);
	if (aDialog.ShowModal() == wxID_CANCEL)
		return;

	wxCopyFile(filename.GetFullPath(), parentPath.GetFullPath());
}
else
{
	wxCopyFile(filename.GetFullPath(), parentPath.GetFullPath());
	myTree->AppendItem(anID, parentPath);

	AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
	if (theRevisionControl->IsAddSupported())
	{
		theRevisionControl->Add(parentPath);
		wxArrayString output = theRevisionControl->GetOutput();
	}
}
