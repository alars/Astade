wxFileName newFilename = GuessGoodDirname("destructor");

if (GetFileName() != newFilename)
{
	newFilename.SetFullName(wxEmptyString);
	wxFileName oldFileName(GetFileName());
	oldFileName.SetFullName(wxEmptyString);

	int rc = AdeRevisionControlBase::GetRevisionControlObject()->Move(oldFileName, newFilename);
	if (rc == 0)
		SetFileName(newFilename);
}
