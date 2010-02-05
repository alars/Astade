wxFileName theFileName(myFileName);
theFileName.SetFullName("code.cpp");

if (!wxFile::Exists(theFileName.GetFullPath().c_str()))
{
	wxFile(theFileName.GetFullPath().c_str(), wxFile::write);

	AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
	if (theRevisionControl->IsAddSupported())
		theRevisionControl->Add(theFileName);
}
