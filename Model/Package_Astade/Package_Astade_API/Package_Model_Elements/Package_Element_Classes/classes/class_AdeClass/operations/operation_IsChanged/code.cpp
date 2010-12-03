//~~ bool IsChanged() [AdeClass] ~~

return GetModificationTime()     > GetSpecGenerationTime() ||
       GetCodeModificationTime() > GetImpGenerationTime();
