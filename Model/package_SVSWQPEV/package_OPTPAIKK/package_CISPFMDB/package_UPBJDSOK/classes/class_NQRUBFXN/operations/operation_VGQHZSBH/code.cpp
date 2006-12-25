wxFileConfig aConfig(wxEmptyString, wxEmptyString, GetFileName().GetFullPath());

wxFileName modelPath;
modelPath.AssignDir(wxConfigBase::Get()->Read("TreeView/ModelPath"));

wxFileName mPath = component.GetFileName();
mPath.MakeRelativeTo(modelPath.GetPath());

wxString aPath =  mPath.GetFullPath(wxPATH_UNIX);
aPath.Replace("/","|");

aConfig.DeleteEntry("Components/" + aPath, true);