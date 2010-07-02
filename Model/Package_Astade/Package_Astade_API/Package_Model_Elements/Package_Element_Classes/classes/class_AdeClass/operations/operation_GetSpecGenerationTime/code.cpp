//~~ wxDateTime GetSpecGenerationTime() [AdeClass] ~~
wxFileName ImpFileName = GetSpecFileName();

if (!ImpFileName.FileExists())
	return wxDateTime(time_t(0));
else
	return ImpFileName.GetModificationTime();