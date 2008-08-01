wxFileName modelPath;
modelPath.AssignDir(wxConfigBase::Get()->Read("TreeView/ModelPath"));
return modelPath;
