wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName activeComponentName = theConfig->Read("TreeView/ActiveComponent");

activeComponentName.AppendDir("auto");
activeComponentName.SetName(GetName());
activeComponentName.SetExt("cpp");

return activeComponentName.GetModificationTime();