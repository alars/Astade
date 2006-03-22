wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();
int type = myTree->GetItem(aID)->GetType();

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName activeComponentName = theConfig->Read("TreeView/ActiveComponent");
wxFileName modelPath;
modelPath.AssignDir(theConfig->Read("TreeView/ModelPath"));
parentPath.MakeRelativeTo(modelPath.GetPath());

wxFileConfig aConfig(wxEmptyString,wxEmptyString,activeComponentName.GetFullPath());
wxString mPath =  parentPath.GetFullPath(wxPATH_UNIX);
mPath.Replace("/","|");

if ((type & ITEM_TYPE_MASK) == ITEM_IS_STATECHART)
	aConfig.DeleteEntry(wxString("Statecharts/") + mPath);
else
	aConfig.DeleteEntry(wxString("Classes/") + mPath);

aConfig.Write("Astade/LastChanged",wxGetUTCTime());
aConfig.Flush();

activeComponentName.AppendDir("auto");
activeComponentName.SetName(myTree->GetItem(aID)->GetName());

activeComponentName.SetExt("cpp");
wxRemoveFile(activeComponentName.GetFullPath());

activeComponentName.SetExt("h");
wxRemoveFile(activeComponentName.GetFullPath());

myTree->UpdateItem(aID);
