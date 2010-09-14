//~~ wxFileName CreateCopy(wxFileName parentPath) [AdeFileElement] ~~
wxFileName source = myFileName;
wxString sourceFileName = source.GetFullName();  //Get source file

wxFileName aFileName = parentPath;
aFileName.SetFullName(sourceFileName);  //Set destination file name same as source.

wxCopyFile(source.GetFullPath(), aFileName.GetFullPath());

AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();  //additional code for version control.
if (theRevisionControl->IsAddSupported())
	theRevisionControl->Add(aFileName);

return aFileName;
