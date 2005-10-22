wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName;
theFileName.AssignDir(theConfig->Read("TreeView/TemplatesPath"));

const wxString& dir = wxFileSelector("Select Makfile",theFileName.GetPath(),"Makefile","","*.*",0,this);
if (dir.empty())
	return;

wxFileName filename(dir);

wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

parentPath.SetFullName("Makefile");

if (parentPath.FileExists())
{
	wxMessageDialog aDialog(this,"File already exists. Overwrite?","Copy Makefile:",wxOK | wxCANCEL | wxICON_EXCLAMATION );
	if (aDialog.ShowModal()==wxID_CANCEL)
		return;
}

wxCopyFile(filename.GetFullPath(),parentPath.GetFullPath());

UpdateSubtree(aID);