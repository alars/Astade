//~~ AdeOperationBase(const wxFileName& theName) [AdeOperationBase] ~~

wxFileName theFileName(myFileName);
theFileName.SetFullName(wxS("code.cpp"));
if (!wxFile::Exists(theFileName.GetFullPath()))
{
	// "code.cpp" doesn't exist, look for "code.<language_ext>"
	AdeClass* aClass = dynamic_cast<AdeClass*>(GetGrandParent());
	if (aClass)
	{
		theFileName.SetExt(aClass->GetImpExtension());
		delete aClass;
	}
	if (!wxFile::Exists(theFileName.GetFullPath()))
	{
		// create "code.<language_ext>"
		wxFile(theFileName.GetFullPath(), wxFile::write);

		AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
		if (theRevisionControl->IsAddSupported())
			theRevisionControl->Add(theFileName);
	}
}
