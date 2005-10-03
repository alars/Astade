wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName activeComponentName = theConfig->Read("TreeView/ActiveComponent");
wxFileName modelPath;
modelPath.AssignDir(theConfig->Read("TreeView/ModelPath"));
parentPath.MakeRelativeTo(modelPath.GetPath());

wxFileConfig aConfig(wxEmptyString,wxEmptyString,activeComponentName.GetFullPath());
wxString mPath =  parentPath.GetFullPath(wxPATH_UNIX);
mPath.Replace("/","|");
aConfig.Write(wxString("Classes/") + mPath, true);
aConfig.Write("Astade/LastChanged",wxGetUTCTime());
aConfig.Flush();

myTree->UpdateItem(aID);