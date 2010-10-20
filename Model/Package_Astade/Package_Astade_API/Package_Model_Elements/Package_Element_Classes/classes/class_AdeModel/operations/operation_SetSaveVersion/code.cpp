//~~ void SetSaveVersion(long aVersion) [AdeModel] ~~

myConfig->Write(wxS("Astade/SaveVersion"), aVersion);
myConfig->Flush();
