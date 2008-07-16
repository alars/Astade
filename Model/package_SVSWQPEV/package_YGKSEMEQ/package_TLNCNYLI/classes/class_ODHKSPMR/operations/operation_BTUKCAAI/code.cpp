wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName theFileName;
theFileName.AssignDir(theConfig->Read("TreeView/TemplatesPath"));

const wxString& dir = wxFileSelector("Select Makefile",theFileName.GetPath(),"Makefile","","*",0,this);  //Creates file select window.
if (dir.empty())  //This condition does not seem work.
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
AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
if (theRevisionControl->IsAddSupported())
{
	theRevisionControl->Add(parentPath);
	wxArrayString output = theRevisionControl->GetOutput();
}

UpdateSubtree(aID);
