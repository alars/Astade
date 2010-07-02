//~~ wxFileName GetSpecFileName() [AdeClass] ~~
wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName activeComponentName = theConfig->Read(wxS("TreeView/ActiveComponent"));

activeComponentName.AppendDir(wxS("auto"));
activeComponentName.SetName(GetName());
activeComponentName.SetExt(wxS("h"));

return activeComponentName;
