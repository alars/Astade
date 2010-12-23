//~~ void Rename() [AdePort] ~~
wxFileName newFilename = GuessGoodFilename(wxS("port_") + GetName());

if (GetFileName() != newFilename)
{
	int rc = AdeRevisionControlBase::GetRevisionControlObject()->Move(GetFileName(), newFilename);
	if (rc == 0)
		SetFileName(newFilename);
}
