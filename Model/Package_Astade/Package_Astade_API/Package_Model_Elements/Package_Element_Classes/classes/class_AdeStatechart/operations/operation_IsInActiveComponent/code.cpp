//~~ bool IsInActiveComponent() [AdeStatechart] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName activeComponentName = theConfig->Read(wxS("TreeView/ActiveComponent"));
wxFileName parentPath(myFileName);
parentPath.MakeRelativeTo(GetModelPath().GetPath());
wxString mPath =  parentPath.GetFullPath(wxPATH_UNIX);
mPath.Replace(wxS("/"), wxS("|"));

wxFileConfig aConfig(wxEmptyString, wxEmptyString, activeComponentName.GetFullPath());
return aConfig.HasEntry(wxS("Statecharts/") + mPath);
