//~~ void MakeMainCpp(wxCommandEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = myTree->GetSelection();   				   	//Get Tree item from mouse click
wxFileName parentPath = myTree->GetItem(anID)->GetFileName();  	//get the parents name
parentPath.SetFullName(wxS("main.cpp")); 						//make full path included file name
bool newFile = true;

if (parentPath.FileExists())
{
	wxMessageDialog aDialog(this, wxS("File already exists. Overwrite?"), wxS("Copy file:"), wxOK | wxCANCEL | wxICON_EXCLAMATION);
	if (aDialog.ShowModal() == wxID_CANCEL)
		return;

	newFile = false;
}

wxFile mainFile(parentPath.GetFullPath(), wxFile::write);

mainFile.Write(wxS("int main(int argc, char** argv)\n"
				"{\n"
				"\t//Write an implementation for the main function here \n"
				"\treturn 0;\n"
				"}\n"));

mainFile.Close();

if (newFile)
{
	myTree->AppendItem(anID,parentPath);

	AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
	if (theRevisionControl->IsAddSupported())
	{
		theRevisionControl->Add(parentPath);
		wxArrayString output = theRevisionControl->GetOutput();
	}
}
