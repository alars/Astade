wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName activeComponentName = theConfig->Read("TreeView/ActiveComponent");

activeComponentName.AppendDir("auto");
activeComponentName.SetName(GetName());
activeComponentName.SetExt("cpp");

if (activeComponentName.FileExists())
    return activeComponentName;
    
activeComponentName.SetExt("c");

if (activeComponentName.FileExists())
    return activeComponentName;
    
activeComponentName.SetExt("cpp");

return activeComponentName;