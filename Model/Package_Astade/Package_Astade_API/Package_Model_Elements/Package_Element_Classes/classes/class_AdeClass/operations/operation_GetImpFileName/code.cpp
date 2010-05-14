wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName activeComponentName = theConfig->Read(wxS("TreeView/ActiveComponent"));

activeComponentName.AppendDir(wxS("auto"));
activeComponentName.SetName(GetName());
activeComponentName.SetExt(wxS("cpp"));

if (activeComponentName.FileExists())
    return activeComponentName;
    
activeComponentName.SetExt(wxS("c"));

if (activeComponentName.FileExists())
    return activeComponentName;
    
activeComponentName.SetExt(wxS("cpp"));

return activeComponentName;
