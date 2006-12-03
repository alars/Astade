wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();
wxFileConfig classConfig(wxEmptyString, wxEmptyString, parentPath.GetFullPath());

int type = myTree->GetItem(aID)->GetType();

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName activeComponentName = theConfig->Read("TreeView/ActiveComponent");
wxFileName modelPath;
modelPath.AssignDir(theConfig->Read("TreeView/ModelPath"));
parentPath.MakeRelativeTo(modelPath.GetPath());

wxFileConfig aConfig(wxEmptyString, wxEmptyString, activeComponentName.GetFullPath());
wxString mPath =  parentPath.GetFullPath(wxPATH_UNIX);
mPath.Replace("/","|");

if ((type & ITEM_TYPE_MASK) == ITEM_IS_STATECHART)
	aConfig.Write(wxString("Statecharts/") + mPath, true);
else
	aConfig.Write(wxString("Classes/") + mPath, true);

aConfig.Write("Astade/LastChanged", wxGetUTCTime());
aConfig.Flush();

/* Save Component-Path to the Class Modelnode.ini */
activeComponentName.MakeRelativeTo(modelPath.GetPath());
mPath = activeComponentName.GetFullPath(wxPATH_UNIX);
mPath.Replace("/","|");

classConfig.Write("Components/" + mPath, true);
classConfig.Write("Astade/LastChanged", wxGetUTCTime());
classConfig.Flush();

myTree->UpdateItem(aID);
