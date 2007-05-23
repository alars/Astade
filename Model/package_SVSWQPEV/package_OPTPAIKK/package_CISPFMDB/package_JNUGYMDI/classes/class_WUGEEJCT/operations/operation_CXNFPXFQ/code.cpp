wxFileName newFilename = GuessGoodDirname("destructor");

if (GetFileName() != newFilename)
{
	newFilename.SetFullName(wxEmptyString);
	wxFileName oldFileName(GetFileName());
	oldFileName.SetFullName(wxEmptyString);

	AdeRevisionControlBase::GetRevisionControlObject()->Move(oldFileName,newFilename);
}