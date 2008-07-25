wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName modelPath;
modelPath.AssignDir(theConfig->Read("TreeView/ModelPath"));
wxFileName parentPath(myFileName);
parentPath.MakeRelativeTo(modelPath.GetPath());
wxString mPath =  parentPath.GetFullPath(wxPATH_UNIX);
mPath.Replace("/","|");

wxFileConfig aConfig(wxEmptyString,wxEmptyString,aComponent.GetFileName().GetFullPath());
return aConfig.HasEntry(wxString("Classes/") + mPath);
