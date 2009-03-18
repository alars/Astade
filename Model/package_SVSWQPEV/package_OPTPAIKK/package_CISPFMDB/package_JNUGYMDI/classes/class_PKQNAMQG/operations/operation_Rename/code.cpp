wxFileName newFilename = GuessGoodFilename("relation_" + GetSortName());

if (GetFileName() != newFilename)
{
	int rc = AdeRevisionControlBase::GetRevisionControlObject()->Move(GetFileName(), newFilename);
	if (rc == 0)
		SetFileName(newFilename);
}
