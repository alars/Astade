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

if ((type & 0x7f00000)==ITEM_IS_STATECHART)
	aConfig.Write(wxString("Statecharts/") + mPath, true);
else
	aConfig.Write(wxString("Classes/") + mPath, true);

aConfig.Write("Astade/LastChanged",wxGetUTCTime());
aConfig.Flush();

myTree->UpdateItem(aID);