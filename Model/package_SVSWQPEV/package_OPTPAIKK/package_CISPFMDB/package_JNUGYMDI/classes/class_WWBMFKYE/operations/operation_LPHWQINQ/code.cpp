wxFileName parentPath(myFileName);
parentPath.MakeRelativeTo(GetModelPath().GetPath());
wxString mPath =  parentPath.GetFullPath(wxPATH_UNIX);
mPath.Replace("/","|");

wxFileConfig aConfig(wxEmptyString,wxEmptyString,aComponent.GetFileName().GetFullPath());
return aConfig.HasEntry(wxString("Classes/") + mPath);
