wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName activeComponentName = theConfig->Read("TreeView/ActiveComponent");
wxFileName modelPath = theConfig->Read("TreeView/ModelPath");
wxFileName parentPath(myFileName);
parentPath.MakeRelativeTo(modelPath.GetPath());
wxString mPath =  parentPath.GetFullPath(wxPATH_UNIX);
mPath.Replace("/","|");

wxFileConfig aConfig(wxEmptyString,wxEmptyString,activeComponentName.GetFullPath());
return aConfig.HasEntry(wxString("Classes/") + mPath);