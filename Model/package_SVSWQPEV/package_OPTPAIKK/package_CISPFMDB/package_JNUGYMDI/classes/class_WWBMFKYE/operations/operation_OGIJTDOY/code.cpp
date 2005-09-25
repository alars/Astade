wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName activeComponentName = theConfig->Read("TreeView/ActiveComponent");

activeComponentName.AppendDir("auto");
activeComponentName.SetName(GetName());
activeComponentName.SetExt("cpp");

if (!activeComponentName.FileExists())
	return wxDateTime(time_t(0));
else
	return activeComponentName.GetModificationTime();