wxFileName newFilename = GuessGoodFilename(wxS("transition_") + GetName());

if (GetFileName() != newFilename)
{
	int rc = AdeRevisionControlBase::GetRevisionControlObject()->Move(GetFileName(), newFilename);
	if (rc == 0)
		SetFileName(newFilename);
}
