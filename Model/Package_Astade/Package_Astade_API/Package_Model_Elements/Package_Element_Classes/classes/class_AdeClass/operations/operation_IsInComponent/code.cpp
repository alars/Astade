wxFileName parentPath(myFileName);
parentPath.MakeRelativeTo(GetModelPath().GetPath());
wxString mPath =  parentPath.GetFullPath(wxPATH_UNIX);
mPath.Replace(wxS("/"), wxS("|"));

wxFileConfig aConfig(wxEmptyString,wxEmptyString,aComponent.GetFileName().GetFullPath());
return aConfig.HasEntry(wxS("Classes/") + mPath);
