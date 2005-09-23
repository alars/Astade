wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName activeComponentName = theConfig->Read("TreeView/ActiveComponent");
wxFileName modelPath = theConfig->Read("TreeView/ModelPath");
wxFileName parentPath(myFileName);
parentPath.MakeRelativeTo(modelPath.GetPath());

wxFileConfig aConfig(wxEmptyString,wxEmptyString,activeComponentName.GetFullPath());
return aConfig.HasEntry(wxString("Classes/") + parentPath.GetFullPath());