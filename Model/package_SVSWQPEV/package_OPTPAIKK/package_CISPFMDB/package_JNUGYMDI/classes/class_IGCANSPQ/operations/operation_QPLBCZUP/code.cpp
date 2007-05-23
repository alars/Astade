wxFileName newFilename = GuessGoodDirname("operation_" + GetName());

if (GetFileName() != newFilename)
{
	newFilename.SetFullName(wxEmptyString);
	wxFileName oldFileName(GetFileName());
	oldFileName.SetFullName(wxEmptyString);

	AdeRevisionControlBase::GetRevisionControlObject()->Move(oldFileName,newFilename);
}