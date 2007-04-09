wxFileName source = myFileName;
wxString sourceFileName = source.GetFullName();  //Get source file

wxFileName aFileName = parentPath;
aFileName.SetFullName(sourceFileName);  //Set destination file name same as source.

wxCopyFile(source.GetFullPath(), aFileName.GetFullPath());

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();  //additional code for version control.
if (theRevisionControl->IsAddSupported())
{
	int ret = theRevisionControl->Add(aFileName);
	wxArrayString output = theRevisionControl->GetOutput();

	if (ret!=0)
	{
		wxString message;
		for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";
	}
}

return aFileName;
