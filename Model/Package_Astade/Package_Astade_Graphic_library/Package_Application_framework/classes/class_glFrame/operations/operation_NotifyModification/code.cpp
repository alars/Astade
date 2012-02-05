//~~ void NotifyModification() [glFrame] ~~

if (!isChanged)
{
	isChanged = true;
	SetTitle(currentFile + wxS(" *"));
}
